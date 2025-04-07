import launch
import launch_ros.actions
import os
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration



def generate_launch_description():
    # Define parameters for the client node
    spider_nav_main_params = {
        'sim_imu': True,
        'input_file': '/home/dfolse/repos/SPIDER_Web/map2.csv', 
        'sim_gps': True
    }

    # Define parameters for the service node
    locomotion_service_params = {
        'sim_imu': True,
        'sim_driver': True
    }

    data_sub_params = {
        'sim_data': True
    }

    # Define parameters for the service node
    gps_params = {
        'sim_gps': True
    }

    imu_params = {
        'sim_imu': True
    }
    
    depthai_prefix = get_package_share_directory("depthai_ros_driver")
    rviz_param = DeclareLaunchArgument('use_rviz', default_value='True')

    return launch.LaunchDescription([
        rviz_param,
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(depthai_prefix, "launch", "example_marker_publish.launch.py"))),
        
        # Launch the client node with parameters
        launch_ros.actions.Node(
            package='spider_nav',
            executable='spider_nav_main',  
            name='spider_nav_main',
            output='screen',
            parameters=[spider_nav_main_params]
        ),
        launch_ros.actions.Node(
            package='data_transfer',
            executable='talker', 
            name='publish_transfer',
            output='screen'
        ),
        launch_ros.actions.Node(
            package='spider_nav',
            executable='spider_gps_pub', 
            name='spider_gps_pub',
            output='screen',
            parameters=[gps_params]
        ),
    ])

