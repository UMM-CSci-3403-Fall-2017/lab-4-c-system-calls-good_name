#!/usr/bin/bash

#store argument and enter directory
dir=$1
cd $dir

#find count of files and directories by piping line counts to respective vars
files=$(find . -type f|wc -l)
direcs=$(find . -type d|wc -l)

#print counts
echo "There were $direcs directories."
echo "There were $files regular files."
