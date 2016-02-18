function extractChannelsFromSlices(img_folder, d, skelCSVName, graphFileName)  
    grid = createMat(img_folder);
    extractChannels(grid, d, skelCSVName, graphFileName);
end