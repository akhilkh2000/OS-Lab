#!/bin/sh
MYVAR="testString"
echo "Usage of ' and \" : "
echo $MYVAR
echo "double quotes gives you $MYVAR"
echo 'single quotes gives you $MYVAR'
CMD='ls'
echo "Usage of \` :"
echo `$CMD`
