This file explains the different code in this project. There is C++ code and MATLAB code.

C++ (src folder)
================
The C++ code contains several different main files for different purposes. They are listed below. In order to switch out one main for another, remove the first from the src folder,
place the new main in the src folder, and then run make in the root directory.

(skel_main.cpp)
    This is probably the most important C++ main, as it takes a csvfile which represents the skeleton produced
    by matlab, and converts it to a ply file, so that the skeleton can be opened in MeshLab.
    It has the following parameters:
        <csvfile> skeleton csvfile
        <plyfile> plyfile to save to
        <xDim> x dimension of skeleton
        <yDim> y dimension of skeleton
        <zDim> z dimension of skeleton
        <r> red color value (0-255)
        <g> green color value (0-255)
        <b> blue color value (0-255)
        -- optional --
        <origX> origin point for bacteria mesh in X
        <origY> origin point for bacteria mesh in Y
        <origZ> origin point for bacteria mesh in Z
        <scalingFactor> scaling factor, multiplied by skeleton's points to scale it to bacteria mesh's scale

(csv_to_ply.cpp)
    This main converts a csvfile containing bacteria centers to a plyfile where each bacteria is represented by a sphere.
    It has the following parameters:
        <csvfile> csv file of bacteria info
        <plyfile> path to plyfile to save to
        <resolution> resolution of spheres (3 is usually good)
        <minR> minimum radius of a sphere for it to be included
        <maxR> maximum radius of a sphere for it to be included
        <radius> radius to set all spheres to which pass the previous two requirements (minR and maxR)
    Note that the last three parameters perform a sort of filtering, only allowing bacteria whose
    radii are between minR and maxR, and setting those bacteria to a radius of parameter radius. If
    you would like to use the actual radius and not do any filtering, set minR, maxR, and radius to -1.

    Also note that the CSVParser is hard-coded to expect the required data to be in the 5th, 6th, 7th, and 14th columns in the csv.
    The 5th column should be x, 6th should be y, 7th should be z, and 14th should be the radius. This can be changed in csvparser.cpp.



(sphere_gen.cpp)
    This main generates a random number of spheres within the given minimum and maximum coordinates and with the given resolution.
    Mostly used for testing the shape creation.

(slicer_main.cpp)
    This is an old main which was used to created slice images from a bacteria centers csv file. We used this to create the slices
    to compare them to the actual data in Avizo.

(density_estimation_test.cpp)
    This is an old main which was used to perform density estimation on the bacteria centers data. We've moved away from this approach
    so you probably won't have much use for it, but incase you do I've left it there.

Matlab (matlab folder)
======================
The matlab code only performs the "channel extraction" on a folder of slices. It uses a library (Skeleton3D) to do the actual skeletonization.
Below is a short description of the methods that are used to do the extraction. Anything not listed is part of Skeleton3D.

(createMat.m)
    This function takes a folder which contains slice images, and creates and returns a 3D grid of 1's and 0's which represents those slices.

(extractChannels.m)
    This function accepts a 3D grid of 0's and 1's representing the data, an integer d representing the minimum diameter in pixels for the channels, and a csv name to
    save the skeletonization result to. To create a mesh from this csv, pass it to skel_main.cpp.

(extractChannelsFromSlices.m)
    This function accepts a folder of slice images, an integer representing the minimum channel diameter in pixels, and a csv name to save the
    skeletonization result to. Essentially this method just calls createMat and then runs extractChannels on the grid it returns.
    To create a mesh from the csv this function creates, pass it to skel_main.cpp.

Channel Extraction Shell Script
===============================
In addition to the C++ and Matlab code, there is also one bash script which performs the entire skeletonization process, including both the Matlab code
and the C++ code. The parameters are as follows:
    <slicesFolder> folder containing slice images
    <minChanSize> minimum required diameter in pixels
    <csvFile> name of csv file to save matlab skeletonization result to
    <plyFile> name of ply file to save skeleton mesh to
    <xDim> x dimension of skeleton (same as x dimension of slice image)
    <yDim> y dimension of skeleton (same as y dimension of slice image)
    <zDim> z dimension of skeleton (same as number of slices)
    <r> red color value for skeleton mesh (0-255)
    <g> green color value for skeleton mesh (0-255)
    <b> blue color value for skeleton mesh (0-255)

After calling this, the skeleton mesh should be in the file <plyFile> specified in the parameters.
