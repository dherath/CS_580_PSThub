#!/bin/bash

#name - Jerome Dinal Herath Muthukumaranage
#B no - B00708543

#gpg -c $1

#if $@
#then
#    for FILE in $@
#    do
#	gpg -c $FILE
#	echo $FILE >> encrypted.log
#    done
#fi

#------------------------------
#echo "Please enter passowrd"
#read PASS
#change gpg line to -> ehco $PASS | gpg -c $FILE
#------------------------------


LIST=`ls`
#runs the command and takes the output of that as variable

if [ $# -gt 0 ]; then
    LIST = $@
fi

for FILE in $LIST; do
    if [ -f $FILE ]; then
	gpg -c $FILE
	echo $FILE >> encrypt.log
    fi
done

echo " DO you want to delete the files?"
read ANS

if [ $ANS = 'y' ]; then
    for FILE in $LIST; do
	rm $FILE
    done
fi

#---------------------------------

#if [ $# -g 0 ]
#then
#    for FILE in $@
#    do
#	gpg -c $FILE
#	echo $FILE >> encrypted.log
#    done   
#else   
#    for NAME in LIST
#    do
#	if [ -f NAME]
#	   gpg -c $NAME
#	   echo $NAME >> encrypted.log
#	fi
#    done
#fi



#echo -n "type rm to delete original file :"
#read COMMAND

#TEXT = "rm"

#if [ COMMAND = TEXT ]
#then
#   $COMMAND $1
#fi
#echo $1 >> encrypted.log
