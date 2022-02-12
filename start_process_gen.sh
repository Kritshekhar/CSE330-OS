#!/bin/bash

export num=$1
echo $num > "var"
name="test_cse330"
home=$(whoami)
sudo useradd $name
sudo passwd -d $name
uid=$(id -u $name)
echo "Please use this UID for testing:" $uid
make

sudo su $name -c ./process_generator
