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
echo $path
if [[ -e "$path" ]]; then
    if [[ -e "/usr/bin/$bin" ]]; then
        echo "$bin is already installed."
        echo "GOODBYE 🙂"
        exit 0
    fi

    echo "Installing $bin in /usr/bin..."
    sleep 1
    sudo cp "$bin" /usr/bin
    echo "$bin has been installed successfully."
else
    echo "Error: $bin not found in the current directory."
    echo "Please make sure the script is in the correct directory."
fi
