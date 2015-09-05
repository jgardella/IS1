function extractChannels(grid, d, skelCSVName)  
    dilationSE = ones(d, d, d);

    disp('Dilating grid');
    dilatedGrid = imdilate(grid, dilationSE); % dilate obstacles
    %disp('Computing complement');
    %flippedGrid = imcomplement(dilatedGrid); % make unoccupied space have 1-value for skeletonization
    disp('Computing skeleton');
    skel = Skeleton3D(dilatedGrid); % compute skeleton
    csvwrite(skelCSVName, skel);
end