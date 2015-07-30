function extractChannels(matFileName, radius, skelCSVName)
    
    
    radius = 100;

    dilationSE = (x/r).^2 + (y/r).^2 + (z/r).^2 <= radius;

    grid = imdilate(grid); % dilate obstacles
    grid = imcomplement(grid); % make unoccupied space have 1-value for skeletonization

    skel = Skeleton3D(dilatedGrid);
    csvwrite(skelCSVName, skel);
end