#!/bin/bash

# For Mac
if [ $(command uname) == "Darwin" ]; then
	if ! [ -x "$(command -v greadlink)"  ]; then
		brew install coreutils
	fi
	BIN_PATH=$(greadlink -f "$0")
	ROOT_DIR=$(dirname $(dirname $(dirname $BIN_PATH)))
# For Linux
else
	BIN_PATH=$(readlink -f "$0")
	ROOT_DIR=$(dirname $(dirname $(dirname $BIN_PATH)))
fi

export ROOT_DIR=${ROOT_DIR}
export PATH=${ROOT_DIR}/clang+llvm/bin:${ROOT_DIR}/tool/SVF/Release-build/bin:$PATH
export LD_LIBRARY_PATH=${ROOT_DIR}/clang+llvm/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}

echo "Installation completed. Everything's fine!"

set -eux

# clean share memory
$ROOT_DIR/tool/staticAnalysis/clean_shm.py

# compile the program and get bit code
cd $ROOT_DIR/rxlitest/simple_three
./cleanDIR.sh
clang -g -O0 -emit-llvm -c ./simple_three.c -o simple_three.bc

# perform static analysis
$ROOT_DIR/tool/staticAnalysis/staticAnalysis.sh simple_three

# complie the instrumented program with ASAN
export Con_PATH=$ROOT_DIR/rxlitest/simple_three/ConConfig.simple_three
$ROOT_DIR/tool/staticAnalysis/DBDS-INSTRU/dbds-clang-fast -g -O0 -fsanitize=address -c ./simple_three.c -o simple_three.o
clang++ ./simple_three.o $ROOT_DIR/tool/staticAnalysis/DBDS-INSTRU/DBDSFunction.o -g -o simple_three -lpthread -fsanitize=address -ldl

