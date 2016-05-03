function saveShorestPath(graphFile, plyOutputFile, r, g, b, scalingFactor, origX, origY, origZ)
    load(graphFile);
    
    [minPath, minCost, pathCount] = shortestPath(A2, node2, .05, .05);
    
    if(minCost ~= Inf)
        fid = fopen(plyOutputFile, 'wt');
        fprintf(fid, 'ply\nformat ascii 1.0\n');

        fprintf(fid, 'element vertex %d\n', length(minPath));
        fprintf(fid, 'property float x\nproperty float y\nproperty float z\n');
        fprintf(fid, 'property uchar red\nproperty uchar green\nproperty uchar blue\n');
        fprintf(fid, 'element face 0\nproperty list uchar int vertex_indices\nend_header\n');
        for i=1:length(minPath)
            node = node2(minPath(i));
            fprintf(fid, '%f %f %f %d %d %d\n', node.comy * scalingFactor + origY, node.comx * scalingFactor + origX, node.comz * scalingFactor + origZ, r, g, b);
        end

        fclose(fid);
    end
   
 end