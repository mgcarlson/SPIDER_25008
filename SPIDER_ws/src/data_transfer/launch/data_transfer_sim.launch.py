import launch
import launch_ros.actions

def generate_launch_description():
    # Define parameters for the client node
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

    return launch.LaunchDescription([
        # Launch the service node with parameters
        launch_ros.actions.Node(
            package='data_transfer',
            executable='talker', 
            name='publish_transfer',
            output='screen'
        ),

        launch_ros.actions.Node(
            package='locomotion',
            executable='imu_pub', 
            name='imu_pub',
            output='screen',
            parameters=[imu_params]
        ),
        launch_ros.actions.Node(
            package='spider_nav',
            executable='spider_gps_pub', 
            name='spider_gps_pub',
            output='screen',
            parameters=[gps_params]
        ),
        
        # Launch the client node with parameters
        launch_ros.actions.Node(
            package='data_transfer',
            executable='listener',  
            name='subscribe_transfer',
            output='screen',
            parameters=[data_sub_params]
        ),
    ])

