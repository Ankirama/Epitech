#!/bin/sh

awk '{print $1}' | sort | uniq
