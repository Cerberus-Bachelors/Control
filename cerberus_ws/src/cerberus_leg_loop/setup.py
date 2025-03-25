from setuptools import find_packages, setup

package_name = 'cerberus_leg_loop'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='v',
    maintainer_email='vegfor07@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'RepeatingTrajectoryNode = cerberus_leg_loop.RepeatingTrajectoryNode:main'
        ],
    },
)
