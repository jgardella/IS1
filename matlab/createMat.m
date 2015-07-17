function createMat( img_folder, matFileName )
   files = dir(strcat(img_folder, '/*.tif'));
   grid = [];
   i = 1;
   for file = files'
       image = imread(strcat(img_folder, '/', file.name)) < 255;
       disp(i);
       grid(:, :, i) = image;
       i = i + 1;
   end

   save(matFileName, 'grid');
end

