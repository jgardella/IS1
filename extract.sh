#!/bin/bash

if [ $# -lt 14 ]; then
    echo "usage: extract.sh <slicesFolder> <minChanSize> <csvFile> <plyFile> <xDim> <yDim> <zDim> <r> <g> <b> <xOrig> <yOrig> <zOrig> <scaleFactor>\n"
else
    SLICES_FOLDER=$1
    MIN_CHAN_SIZE=$2
    CSV_FILE=$3
    PLY_FILE=$4
    X_DIM=$5
    Y_DIM=$6
    Z_DIM=$7
    RED=$8
    GREEN=$9
    shift 9
    BLUE=$1
    X_ORIG=$2
    Y_ORIG=$3
    Z_ORIG=$4
    SCALE_FACTOR=$5
    matlab -nodisplay -r "addpath(genpath('matlab/'));extractChannelsFromSlices('$SLICES_FOLDER', $MIN_CHAN_SIZE, '$CSV_FILE');exit"
    ./skel_csvtoply $CSV_FILE $PLY_FILE $X_DIM $Y_DIM $Z_DIM $RED $GREEN $BLUE $X_ORIG $Y_ORIG $Z_ORIG $SCALE_FACTOR
fi
