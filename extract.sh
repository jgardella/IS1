#!/bin/bash

if [ $# -lt 10 ]; then
    echo "usage: extract.sh <slicesFolder> <minChanSize> <csvFile> <plyFile> <xDim> <yDim> <zDim> <r> <g> <b>\n"
else
    #matlab -nodisplay -r "addpath(genpath('matlab/'));extractChannelsFromSlices('$1', $2, '$3');exit"
    ./skel_csvtoply $3 $4 $5 $6 $7 $8 $9 $10
fi
