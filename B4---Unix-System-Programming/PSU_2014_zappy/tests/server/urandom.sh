#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Usage: ./urandom.sh port"
    exit
fi

echo "urandom will start"
echo `nc localhost $1 < /dev/urandom`
