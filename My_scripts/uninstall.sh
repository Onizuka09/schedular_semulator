#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "This script must be run with sudo or as root."
    exit 1
fi

#bin=scheduler_simulator
bin="schedular_semulator"
path=$PWD/$bin
# script_dir="$(dirname "$0")"
# path="$script_dir/$bin"
# echo $path

if [[ -e "/usr/bin/$bin" ]]; then
    echo "removing $bin."
    rm $path
    echo "GOODBYE 🙂"
    exit 0
fi

 