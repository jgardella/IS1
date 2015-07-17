clear all;
close all;

load mat

skel = Skeleton3D(grid);
save('skeleton', 'skel');
