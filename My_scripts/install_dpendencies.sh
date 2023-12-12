#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "This script must be run with sudo or as root."
    exit 1
fi

if dpkg -l | grep -q "libgtk-3-dev"; then
    echo "libgtk-3-dev exists."
else 
    echo "libgtk-3-dev doesn't exist."
    echo "Do you want to install it now? [y/n]"  
    read -r x
    if [ "$x" == "y" ]; then 
        sudo apt install -y libgtk-3-dev
        echo "finished installing libgtk-3-dev"
    else 
        echo "GOODBYE 🙂"
    fi

