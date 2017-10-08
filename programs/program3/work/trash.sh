#!/bash/bin -xv

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
	else
	    echo " $FILE is not in directory "
	fi
    done   
    
    #------------------------------------------------
else
    echo "no arguments given "
fi



