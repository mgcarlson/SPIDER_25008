from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'spider_nav'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='danielfolse@arizona.edu',
    description='package for following GPS waypoints with nav2',
    license='Apache',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'logged_waypoint_follower = spider_nav.logged_waypoint_follower:main',
            'interactive_waypoint_follower = spider_nav.interactive_waypoint_follower:main',
            'gps_waypoint_logger = spider_nav.gps_waypoint_logger:main',
            'spider_gps_pub = spider_nav.spider_gps_pub:main',
            'spider_nav_main = spider_nav.spider_nav_main:main'
        ],
    },
)