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

    # Define parameters for the service node
    locomotion_service_params = {
        'sim_imu': False,
        'sim_driver': False
    }

    data_sub_params = {
        'sim_data': False
    }


    imu_params = {
        'sim_imu': False
    }

    return launch.LaunchDescription([
        # Launch the service node with parameters
        launch_ros.actions.Node(
            package='locomotion',
            executable='service', 
            name='locomotion_service',
            output='screen',
            parameters=[locomotion_service_params]
        ),
        
        launch_ros.actions.Node(
            package='locomotion',
            executable='imu_pub', 
            name='imu_pub',
            output='screen',
            parameters=[imu_params]
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

