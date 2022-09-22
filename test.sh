#!/bin/bash
export num=$1
echo $num > var
name="test_cse330"
home=$(whoami)
useradd $name
passwd -d $name
uid=$(id -u $name)
make clean
make
echo "Test script will start $num processes for the user $uid"
su $name -c ./process_gen/process_generator &
sleep 10
PS_SCRIPT=`bash ps_time.sh $uid &`
let OUTPUT
OUTPUT="$PS_SCRIPT";
echo "Test script will insert the test kernel module"
insmod producer_consumer.ko buffSize=$2 prod=$3 cons=$4 uuid=$uid &&
echo "The test script waits 10 seconds for the kernel module to finish"
sleep 10
echo "Test script will remove the test kernel module"
rmmod producer_consumer;
echo "The following is the dmesg output"
dmesg | tail -n $5; echo $OUTPUT;
pkill -u $uid; rm -rf var;
