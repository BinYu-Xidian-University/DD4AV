#!/bin/bash

toolPath=~/conc-tools/interrupts

ESBMC=$toolPath/esbmc-v1.23-linux-64-static/bin/esbmc
THREADER=./threader.sh

fileName=$1
exptName=$2
prpFile='ALL.prp'

currFolder=`pwd`
dataFolder=$currFolder/'data-'$exptName
dataName=$dataFolder/'data_'$exptName
timeName=$dataFolder/'time_'$exptName

if [ -d $dataFolder ]
then
  echo "Folder " + $dataFolder + " already exists. "
  exit
fi

mkdir $dataFolder

(time $ESBMC -DCBMC -DREAL_T=float -DREAL32_T=float --timeout 30m --memlimit 15g --64 --unwind 1 --no-unwinding-assertions --no-assertions --error-label ERROR --no-bounds-check --no-div-by-zero-check --no-pointer-check $fileName &> $dataName'_esbmc.txt') &>> $timeName'_esbmc.txt'

cd ~/conc-tools/interrupts/threader-sv-comp-2014/
(time $THREADER $currFolder/$fileName &> $dataName'_threader.txt') &>> $timeName'_threader.txt'
