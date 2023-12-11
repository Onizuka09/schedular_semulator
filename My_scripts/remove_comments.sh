#!/bin/bash
echo $PWD
remove_comments(){
    local f=$1
    if [[ -e $f ]]; then
    	echo "cleaning $f ..."
    	sed -i 's/\/\/.*$//' $f	;			# reomve // 
		sed -i 's/\/\*.*\*\///' $f; 
    	sed -i '/\/\*/,/\*\//d' $f;			# reomves /* */  
    	sed -i '/^[[:space:]]*$/d' $f ;       # reomves empty lines 
    else 
    	echo "file doesn't exist" ;
    fi 

}