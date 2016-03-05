function [minPath, minCost] = shortestPath(am, nodes, endNodePercentage)
 % calculates the shortest path through the graph from the rightmost node (highest y)
 % to the given percentage of leftmost nodes (lowest y).
 % returns a list representing the nodes in the path, and the cost of the
 % path
[B, I] = sort([nodes.comy]);
 
 endNodeCount = ceil(length(I) * endNodePercentage);
 startNode = I(end);
 endNodes = I(1 : endNodeCount);
 
[costs, paths] = dijkstra(am, am, startNode, endNodes);
[minCost, minIdx] = min(costs);
minPath = paths{1, minIdx};

end

