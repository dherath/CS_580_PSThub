#!/bin/bash

#name - Jerome Dinal Herath Muthukumaranage
#B no - B00708543

LIST=$@

if [ $# -gt 0 ];then
    #------Making TRASH directory if needed-----------
    TEMP=0
    ITEMS=`ls`
    for THINGS in $ITEMS ; do
	if [ -d $THINGS ] && [ "$THINGS" = 'TRASH' ]; then
	    TEMP=1
	fi
    done

    if [ $TEMP -eq 0 ]; then
	mkdir $PWD/TRASH
    fi
    #----------moving to TRASH-----------------------
    for FILE in $LIST ; do
	if [ -f $FILE ]; then
	    mv $FILE TRASH/
	elif [ -d $FILE ]; then
	    echo " $FILE is a directory "
	else
	    echo " $FILE is not in directory "
	fi
    done   
    #-------- removing file based on time stamp------
    cd TRASH
    TRASH_LIST=`ls`
    HOUR=$((60*60))
    for FILE in $TRASH_LIST ; do
	TIME=$(( $(date +%s) - $(date +%s -r $FILE) ))
	if [ $TIME -gt $HOUR ]; then
	    rm $FILE
	fi
    done
    cd ..
    #------------------------------------------------
else
    echo "no arguments given "
fi



