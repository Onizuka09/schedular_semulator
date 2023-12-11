#!/bin/bash
path=$PWD/My_scripts/remove_comments.sh 
source "$path" 

echo "Searching for .h and .c files in the current directory..."

files=$(find . -maxdepth 2 -type f \( -name "*.h" -o -name "*.c" \))

if [ -n "$files" ]; then
    for file in $files; do 
         remove_comments "$file"
    done 
else
    echo "No .h or .c files found in the current directory: $PWD"
fi
