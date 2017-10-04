#!/bin/sh

if [ $# -lt 2 ]; then 
    echo "You've to specifie an argument"
    echo -e "Example : ./myman.sh ls coffre-fort\n"
    exit 0
fi

if [ -f "$2" ]; then 

    command=$(grep -i "$1(1)" "$2")

    if [ "$command" = "" ]; then
	echo "commande non trouvée dans le coffre-fort"
	exit 0
    fi
else
    echo "File not found"
fi

start=$(cat -n "$2" | grep -i "$1(1)" | head -1 | awk '{print $1}')
end=$(cat -n "$2" | grep -i "$1(1)" | tail -1 | awk '{print $1}')

sed -ne "$start,$end p" "$2"
