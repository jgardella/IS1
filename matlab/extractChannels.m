function extractChannels(grid, d, skelCSVName, graphFileName)  
    dilationSE = ones(d, d, d);

    disp('Dilating grid');
    erodedGrid = imerode(grid, dilationSE); % dilate obstacles
    %disp('Computing complement');
    %flippedGrid = imcomplement(dilatedGrid); % make unoccupied space have 1-value for skeletonization
    disp('Computing skeleton');
    skel = Skeleton3D(erodedGrid); % compute skeleton
    csvwrite(skelCSVName, skel);
    saveGraph(skel, graphFileName);
    
end