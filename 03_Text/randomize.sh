#!/bin/sh

TMPFILE="$(mktemp)"
TMPFILE2="$(mktemp)"

Y=0
while IFS= read -r LINE; do

    X=0
    STRING=$(echo "$LINE" | od -b -v -A n )

    for CHAR in $STRING; do

        echo $X $Y $CHAR >> $TMPFILE
        X=$((X+1))
    done
    Y=$((Y+1))
done

shuf $TMPFILE > $TMPFILE2

tput clear
while IFS= read -r LINE; do

    X=${LINE%% *}
    HEAD=${LINE% *}
    Y1=${HEAD#* }
    CHAR=${LINE##* }

    tput cup $Y1 $X

    echo "\\$CHAR"
    if [ $1 ]; then
        sleep $1
    fi
done < $TMPFILE2
tput cup $Y 0
