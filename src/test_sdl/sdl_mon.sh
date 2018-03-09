#! /bin/bash
process_desc='./sdl_test'
out_file='sdl_monitor.txt'
while true; do
    pid=`ps -ef|grep $process_desc|grep -v grep|awk '{print $2}'`
    if [ ! -e "$out_file" ]; then
        echo "DATETIME  PID   %CPU    VSZ   RSS" | column -t >> $out_file
    fi
    t=`date "+%Y-%m-%d %H:%M:%S"`
if [ ! -z "$pid" ]; then
	m=`ps -o "pid,%cpu,vsz,rss" -p $pid | tail -n 1 | column -t`
	echo ${t}" "${m}|column -t >> $out_file
fi
    sleep 2
done

