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
  #exit
fi

#mkdir $dataFolder

#(time $SATABS $fileName -DCBMC -DREAL_T=float -DUSE_FLOAT &> $dataName'_satabs.txt') &>> $timeName'_satabs.txt'

#(time $CBMC $fileName -DCBMC -DREAL_T=float -DUSE_FLOAT &> $dataName'_cbmc.txt') &>> $timeName'_cbmc.txt'

#(time $IMPARA --eager $fileName -DCBMC -DREAL_T=float -DUSE_FLOAT &> $dataName'_impara2.txt') &>> $timeName'_impara2.txt'
#
#
(time $IMPARA $fileName -DCBMC -DREAL_T=float -DUSE_FLOAT &> $dataName'_impara.txt') &>> $timeName'_impara.txt'
