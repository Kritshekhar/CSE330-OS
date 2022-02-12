#!/bin/bash
let TIME=0
echo $1
for pid in $(ps -u $1 | awk '{print $1}'); do
	if [[ "$pid" == "PID" ]]; then
		continue
	else
		TMP=$(ps -p $pid -o etimes=)
		let TIME=$((TIME+TMP))
	fi
done
HR=$(($TIME/3600))
MIN=$((($TIME-3600*$HR)/60))
SEC=$((($TIME-3600*$HR)-($MIN*60)))
op="$HR:$MIN:$SEC"
echo "Total Elapsed Time from PS Command $op"
