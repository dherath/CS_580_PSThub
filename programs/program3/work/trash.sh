#!/bash/bin -xv

#name - Jerome Dinal Herath Muthukumaranage
#B no - B00708543

LIST=$@

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

#------------------------------------------------


