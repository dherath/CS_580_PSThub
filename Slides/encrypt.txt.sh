#!/bin/bash -x
echo "Please enter a passphrase to use for encryption"
read PASS
LIST=`ls`
if [ $# -gt 0 ]; then
    LIST=$@
fi
for FILE in $LIST; do
    echo $PASS | gpg --passphrase-fd 0 -c $FILE
done
echo "Do you want to delete the original files? (y/n)"
read ans
if [ $ans = 'y' ]; then
    for FILE in $LIST; do
        rm  $FILE
    done
fi
