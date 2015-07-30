function grid = createMat( img_folder )
   files = dir(strcat(img_folder, '/*.tif'));
   grid = [];
   i = 1;
   for file = files'
       image = imread(strcat(img_folder, '/', file.name)) < 255;
       grid(:, :, i) = image;
       i = i + 1;
   end
end

