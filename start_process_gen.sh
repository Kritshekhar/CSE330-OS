#!/bin/bash

export num=$1
echo $num > "var"
name="test_cse330"
home=$(whoami)
sudo useradd $name
sudo passwd -d $name
uid=$(id -u $name)
make
echo "Please use this UID for testing:" $uid
sudo su $name -c ./process_generator
