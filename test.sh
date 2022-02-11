#!/bin/bash
PS_SCRIPT=`bash ps_time.sh $1`
let OUTPUT
make; sudo insmod producer_consumer.ko uid=$1 buff_size=$2 p=$3 c=$4; sudo rmmod producer_consumer; OUTPUT=$PS_SCRIPT; dmesg | tail -n 5; echo $OUTPUT; sudo pkill -u $1; rm -rf var;
