#!/bin/bash

set -e
DIR=`dirname $0`
COMMON_SH=$DIR/common.sh
if [ ! -e "$COMMON_SH" ]; then
    echo "ERROR: unable to find common.sh at $COMMON_SH"
    exit 1
fi

source $COMMON_SH

set -u

if [ ! -d "$NSPR_SRC" ]; then 
    echo
    echo "Unzipping NSPR Source..."
    cd $SRC_DIR
    tar xzf $NSPR_ZIP
    if [ ! -d "$NSPR_SRC" ]; then
        echo "ERROR: unzip failed to create $NSPR_SRC"
        exit 1
    fi
    cp $NSPR_SRC/../os_Linux_x86.s $NSPR_SRC/mozilla/nsprpub/pr/src/md/unix/
    cp $NSPR_SRC/../os_Linux_x86_64.s $NSPR_SRC/mozilla/nsprpub/pr/src/md/unix/
fi

if [ ! -d "$JS_SRC" ]; then 
    echo
    echo "Unzipping JS Source..."
    cd $SRC_DIR
    tar xzf $JS_ZIP
    if [ ! -d "$JS_SRC" ]; then
        echo "ERROR: unzip failed to create $JS_SRC"
        exit 1
    fi
    sed  -i  '1,100s/CC = gcc/CC = wllvm/g' $JS_SRC/src/config/Linux_All.mk
    sed  -i  '1,100s/CCC = g++/CCC = wllvm++/g' $JS_SRC/src/config/Linux_All.mk
fi

echo
echo "Starting Building NSPR..."
mkdir -p $NSPR_TARGET
cd $NSPR_TARGET
CC=wllvm CXX=wllvm++ ../mozilla/nsprpub/configure --enable-64bit
make
make install
echo "NSPR installed to $NSPR_INSTALL"

echo
echo "Starting JS build..."
cd $JS_SRC_SRC
LD_LIBRARY_PATH=${NSPR_INSTALL}/lib:${LD_LIBRARY_PATH} XCFLAGS="-I$NSPR_INSTALL/include/nspr" XLDFLAGS="-L$NSPR_INSTALL/lib -lplc4 -L$NSPR_INSTALL/lib -lnspr4 -lpthread" JS_THREADSAFE=1 make -f Makefile.ref
echo "JS built"
