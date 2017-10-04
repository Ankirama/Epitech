#!/bin/sh

cut -d[ -f11 > /tmp/file.tmp
sed -i '/^$/d' /tmp/file.tmp
cat /tmp/file.tmp
rm /tmp/file.tmp
