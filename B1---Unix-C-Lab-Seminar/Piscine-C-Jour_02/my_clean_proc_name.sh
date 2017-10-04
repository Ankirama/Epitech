#!/bin/sh

awk '{ for (i=11; i <= NF; i++) printf("%s ", $i); printf("\n")}' | cut -d[ -f1 | sed '/^$/d' > ./file.tmp

while read line
do 
    var=$(echo "$line" | awk '{print $1}')
    if [ "$var" = "-:0" ]; then
	echo "$line"
    else
	echo `basename "$var"` `echo "$line" | awk '{for (i=2; i <= NF; i++) printf("%s ", $i); printf("\n")}'`
    fi
done < ./file.tmp
rm ./file.tmp
