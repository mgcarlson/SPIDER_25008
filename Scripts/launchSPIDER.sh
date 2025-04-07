#!bin/sh
get_ws_path() {
	cd /home/alexcc/repos/SPIDER_25008/SPIDER_ws
	spider_path=$(pwd)

}
launch_GPS() {
	get_ws_path
	source install/setup.bash
	ros2 run spider_nav spider_gps_pub
}
launch_IMU() {
	if [ $1 == 'SIM' ]; then 
		export SIM_IMU=1
	else
		export SIM_IMU=0
	fi
	get_ws_path
	source install/setup.bash
	ros2 run locomotion imu_pub
}
bk() {
	cd ../Scripts
}
