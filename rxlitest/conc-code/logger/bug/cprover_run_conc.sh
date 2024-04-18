#!/bin/bash

CBMC=~/cbmc-trunk/src/cbmc/cbmc
IMPARA=~/impara/trunk/src/impara/impara
SATABS=~/conc-tools/satabs-3.2/satabs

fileName=$1
exptName=$2

currFolder=.
dataFolder=$currFolder/'data-'$exptName
dataName=$dataFolder/'data_'$exptName
timeName=$dataFolder/'time_'$exptName

if [ -d $dataFolder ]
then
  echo "Folder " + $dataFolder + " already exists. "
  exit
fi

mkdir $dataFolder

#(time $SATABS $fileName &> $dataName'_satabs.txt') &>> $timeName'_satabs.txt'
#
(time $CBMC --unwind 1 --no-unwinding-assertions $fileName &> $dataName'_cbmc.txt') &>> $timeName'_cbmc.txt'

(time $IMPARA --dpor --eager $fileName &> $dataName'_impara3.txt') &>> $timeName'_impara3.txt'

#(time $IMPARA $fileName &> $dataName'_impara.txt') &>> $timeName'_impara.txt'

