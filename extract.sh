#!/bin/bash

if [ $# -lt 14 ]; then
    echo "usage: extract.sh <slicesFolder> <minChanSize> <csvFile> <graphFile> <plyFile> <xDim> <yDim> <zDim> <r> <g> <b> <xOrig> <yOrig> <zOrig> <scaleFactor>"
else
    SLICES_FOLDER=$1
    MIN_CHAN_SIZE=$2
    CSV_FILE=$3
	GRAPH_FILE=$4
    PLY_FILE=$5
    X_DIM=$6
    Y_DIM=$7
    Z_DIM=$8
    RED=$9
    shift 9
    GREEN=$1
    BLUE=$2
    X_ORIG=$3
    Y_ORIG=$4
    Z_ORIG=$5
    SCALE_FACTOR=$6
    matlab -nodisplay -r "addpath(genpath('matlab/'));extractChannelsFromSlices('$SLICES_FOLDER', $MIN_CHAN_SIZE, '$CSV_FILE', '$GRAPH_FILE');exit"
    ./skel_csvtoply $CSV_FILE $PLY_FILE $X_DIM $Y_DIM $Z_DIM $RED $GREEN $BLUE $X_ORIG $Y_ORIG $Z_ORIG $SCALE_FACTOR
fi
