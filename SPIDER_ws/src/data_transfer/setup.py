from setuptools import find_packages, setup
import os
from glob import glob
package_name = 'data_transfer'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='danielfolse',
    maintainer_email='danielcfolse@gmail.com',
    description='DataTransfer software for collecting and transferring data for the SPIDER robot',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'talker = data_transfer.publish_transfer:main',
                'listener = data_transfer.subscribe_transfer:main',
        ],
},
)
