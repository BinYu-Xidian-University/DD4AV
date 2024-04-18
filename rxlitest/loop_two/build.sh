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

# compile the program and get bit code
cd $ROOT_DIR/rxlitest/loop_two
./cleanDIR.sh
clang -g -O0 -emit-llvm -c ./loop_two.c -o loop_two.bc

# perform static analysis
$ROOT_DIR/tool/staticAnalysis/staticAnalysis.sh loop_two

# complie the instrumented program with ASAN
export Con_PATH=$ROOT_DIR/rxlitest/loop_two/ConConfig.loop_two
$ROOT_DIR/tool/staticAnalysis/DBDS-INSTRU/dbds-clang-fast -g -O0 -fsanitize=address -c ./loop_two.c -o loop_two.o
clang++ ./loop_two.o $ROOT_DIR/tool/staticAnalysis/DBDS-INSTRU/DBDSFunction.o -g -o loop_two -lpthread -fsanitize=address -ldl

