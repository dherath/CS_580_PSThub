#!/bash/bin

#name - Jerome Dinal Herath Muthukumaranage
#B no - B00708543

gpg -c $1

echo -n "type rm to delete original file :"
read COMMAND

$COMMAND $1

echo $1 >> encrypted.log
