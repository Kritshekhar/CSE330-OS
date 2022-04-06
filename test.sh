#!/bin/bash
make clean
make
gcc userspace.c -o userspace
clear;

free -h;
echo "---------------------- Test Case: $1 -----------------------------"
sudo dmesg -c > /dev/null

if [[ $1 -le 2 ]]; then

	./userspace $1 &
	pid=$!

	echo "Loading the test kernel module ..."
        sudo insmod memory_manager.ko pid=$pid

	count=1
	while [ $count -le 3 ]
	do
		sleep 10
		vmRss=( $(sudo cat /proc/$pid/smaps | grep Rss: | awk '{print $2}' | awk '{ SUM += $1} END { print SUM }') )
		vmSwap=( $(sudo cat /proc/$pid/smaps | grep Swap: | awk '{print $2}' | awk '{ SUM += $1} END { print SUM }') )
		echo "[TESTSCRIPT] [PID-$pid] Reported [RSS:$vmRss KB] [Swap:$vmSwap KB]"
		((count++))
	done

	echo "Removing the test kernel module ..."
        sudo rmmod memory_manager

	echo "The following is the dmesg output"
        sudo dmesg | grep $pid
	echo "----------------------------------------------------------------------------------";
        echo ""
else
	# Swap Test Case
	scalar=3.5
	one_gb=1073741824
	index=1
	while [ $index -le 3 ]; do
		mem_size_gb=$(echo "scale=2; ($scalar*$one_gb)/1073741824" | bc)

		echo "---------------------------------------------------------------------";
		echo "------- SWAP Test Case iteration: $index with Memory Size : $mem_size_gb GB ------"
		echo "---------------------------------------------------------------------";
		./userspace $1 $scalar &
		pid=$!

		echo "Loading the test kernel module ..."
		sudo insmod memory_manager.ko pid=$pid
		count=1

		while [ $count -le 3 ]
		do
			sleep 10
			vmRss=( $(sudo cat /proc/$pid/smaps | grep Rss: | awk '{print $2}' | awk '{ SUM += $1} END { print SUM }') )
			vmSwap=( $(sudo cat /proc/$pid/smaps | grep Swap: | awk '{print $2}' | awk '{ SUM += $1} END { print SUM }') )
			echo "[TESTSCRIPT] [PID-$pid] Reported [RSS:$vmRss KB] [Swap:$vmSwap KB]"
			((count++))
		done

		echo "Removing the test kernel module ..."
		sudo rmmod memory_manager

		echo "The following is the dmesg output"
		sudo dmesg | grep $pid
		echo "----------------------------------------------------------------------------------";
		echo ""
		killall userspace
		((index++))
		scalar=$(echo "scala=2; $scalar + 0.5" | bc)
	done

fi
killall userspace
rm userspace
