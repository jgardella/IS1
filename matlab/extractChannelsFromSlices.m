function extractChannelsFromSlices(img_folder, d, skelCSVName)  
    grid = createMat(img_folder);
    extractChannels(grid, d, skelCSVName);
end