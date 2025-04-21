import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from cv_bridge import CvBridge
from spider_interfaces.msg import WeedTarget
import torch
from torchvision.models.detection import fasterrcnn_resnet50_fpn, FastRCNNPredictor
from torchvision.transforms import functional as F
import numpy as np
import cv2

class WeedDetectorController(Node):
    def __init__(self):
        super().__init__('weed_detector_node')

        self.image_sub = self.create_subscription(
            Image,
            '/oak/rgb/image_raw',
            self.image_callback,
            10
        )

        self.weed_target_pub = self.create_publisher(WeedTarget, '/weed_target', 10)
        self.bridge = CvBridge()

        self.model = self.load_model('SPIDER_ws/src/weed_detection/weed_fasterrcnn_final.pth')
        self.model.eval()
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.model.to(self.device)

    def load_model(self, path):
        model = fasterrcnn_resnet50_fpn(pretrained=False)
        in_features = model.roi_heads.box_predictor.cls_score.in_features
        model.roi_heads.box_predictor = FastRCNNPredictor(in_features, 2)
        model.load_state_dict(torch.load(path, map_location=self.device))
        return model

    def image_callback(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        image_rgb = cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB)
        image_tensor = F.to_tensor(image_rgb).unsqueeze(0).to(self.device)

        with torch.no_grad():
            prediction = self.model(image_tensor)[0]

        boxes = prediction['boxes']
        scores = prediction['scores']

        confident_indices = [i for i, s in enumerate(scores) if s >= 0.75]
        if not confident_indices:
            return 
        
        best_idx = confident_indices[torch.tensor([scores[i] for i in confident_indices]).argmax()]
        best_box = boxes[best_idx].cpu().numpy()
        best_score = scores[best_idx].item()

        x1, y1, x2, y2 = best_box
        target_x = float((x1 + x2) / 2)
        target_y = float(y2 - 0.05 * (y2 - y1)) 

        self.get_logger().info(f"Detected weed at ({target_x:.1f}, {target_y:.1f}) with confidence {best_score:.2f}")

        msg = WeedTarget()
        msg.x = target_x
        msg.y = target_y
        msg.stop_movement = True
        self.weed_target_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = WeedDetectorController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
