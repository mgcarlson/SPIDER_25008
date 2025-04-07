from setuptools import find_packages
from setuptools import setup

setup(
    name='spider_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('spider_interfaces', 'spider_interfaces.*')),
)
