#!/bin/sh 

sed "/$USER/!d" | sort -rk 4
