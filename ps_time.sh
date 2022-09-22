#!/bin/bash
let TIME=0
etimes=$(ps -u $1 -o etimes= | awk '{print $1}')
etimesList=($etimes)
etimesLen=${#etimesList[@]}
for ((j=0; j<${etimesLen}; j++)); do
	let TIME=$((TIME+${etimesList[$j]}))
done

HR=$(($TIME/3600))
MIN=$((($TIME-3600*$HR)/60))
SEC=$((($TIME-3600*$HR)-($MIN*60)))

op="$HR:$MIN:$SEC"
echo "Total Elapsed Time from PS Command $op"
