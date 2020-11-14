#!/bin/sh

TARGET=/mnt/data/pgsrc/compiler/comp-004

#if [ "$UID" != "0" ] ; then
#	echo Only root can do that;
#	exit;
#fi

if [ ! -d $TARGET ] ; then
    echo "Target dir ($TARGET) does not exist, creating ... "
    mkdir -p $TARGET
fi

cp -au * $TARGET

