function displayGraph(fileName)  
        load(fileName);

        % display result
        figure();
        hold on;
        for i=1:length(node2)
            x1 = node2(i).comx;
            y1 = node2(i).comy;
            z1 = node2(i).comz;

            if(node2(i).ep==1)
                ncol = 'c';
            else
                ncol = 'y';
            end;

            for j=1:length(node2(i).links)    % draw all connections of each node
                if(node2(link2(node2(i).links(j)).n2).ep==1)
                    col='k'; % branches are blue
                else
                    col='k'; % links are red
                end;
                if(node2(link2(i).n1).ep==1)
                    col='k';
                end;


                % draw edges as lines using voxel positions
                for k=1:length(link2(node2(i).links(j)).point)-1            
                    [x3,y3,z3]=ind2sub([w,l,h],link2(node2(i).links(j)).point(k));
                    [x2,y2,z2]=ind2sub([w,l,h],link2(node2(i).links(j)).point(k+1));
                    line([y3 y2],[x3 x2],[z3 z2],'Color',col,'LineWidth',2);
                end;
            end;

            % draw all nodes as yellow circles
            plot3(y1,x1,z1,'o','Markersize',9,...
                'MarkerFaceColor',ncol,...
                'Color','k');
        end;
           
        % draw shortest path as green
        [minPath, minCost, pathCount] = shortestPath(A2, node2, .05, .05);
        if(minCost ~= Inf)
            for i=1:length(minPath)-1
               nodeA = node2(minPath(i));
               nodeB = node2(minPath(i + 1));
               line([nodeB.comy nodeA.comy], [nodeB.comx nodeA.comx], [nodeB.comz nodeA.comz], 'Color','g','LineWidth',5);
               if (i ~= 1)
                    plot3(nodeA.comy, nodeA.comx, nodeA.comz, 'o', 'Markersize', 12, 'MarkerFaceColor', 'g', 'Color', 'k');
               end
            end
            % display start and end node as magenta
            firstNode = node2(minPath(1));
            lastNode = node2(minPath(end));
            plot3(firstNode.comy, firstNode.comx, firstNode.comz, 'o', 'Markersize', 12, 'MarkerFaceColor', 'm', 'Color', 'k');
            plot3(lastNode.comy, lastNode.comx, lastNode.comz, 'o', 'Markersize', 12, 'MarkerFaceColor', 'm', 'Color', 'k');
            disp(['Found path of length ' num2str(minCost) '.']);
            disp(['Number of paths: ' num2str(pathCount) '.']);
        else
            display('No path found.');
        end

        axis image;axis off;
        set(gcf,'Color','white');
        drawnow;
end