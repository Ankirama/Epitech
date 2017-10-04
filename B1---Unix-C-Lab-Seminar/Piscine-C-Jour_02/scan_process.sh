#!/bin/sh

count=0
while [ "$count" -ne "$2" ]; do
    ps auxh > ./tmp.file
    sed "/$1/!d" ./tmp.file | awk '{print $3,$4}'
    echo ""
    sleep 0.01
    count=$(($count +1))
done

rm ./tmp.file
