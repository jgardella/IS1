function [minPath, minCost, pathCount] = shortestPath(am, nodes, startNodePercentage, endNodePercentage)
 % calculates the shortest path through the graph from
 % the given percentage of rightmost nodes (highest y)
 % to the given percentage of leftmost nodes (lowest y).
 % returns a list representing the nodes in the path, and the cost of the
 % path
[B, I] = sort([nodes.comy]);
 
startNodeCount = ceil(length(I) * startNodePercentage);
 endNodeCount = ceil(length(I) * endNodePercentage);
 startNode = I(end - startNodeCount : end);
 endNodes = I(1 : endNodeCount);
 
[costs, paths] = dijkstra(am, am, startNode, endNodes);
[minRowCost, minRowIdxVector] = min(costs);
[minCost, minCol] = min(minRowCost);
minPath = paths{minRowIdxVector(minCol), minCol};

% calcluate number of paths from start nodes to end nodes
pathCount = 0;
[rows, cols] = size(costs);
for i=1:rows
    for j=1:cols
        if (costs(i, j) ~= Inf)
            pathCount = pathCount + 1;
        end
    end
end

