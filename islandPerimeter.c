/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, a
nd there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" 
(water inside that isn't connected to the water around the island). One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/

#include "stdio.h"
#include "string.h"

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {

    int island = 0;
    int sused = 0;

    for (int i = 0; i < gridRowSize; ++i)
    {
        for (int j = 0; j < gridColSize; ++j)
        {
            if (grid[i][j] == 1)
            {
                island++;

                if(i < gridRowSize-1 && j < gridColSize-1){
                    if (grid[i+1][j] == 1) ++sused;
                    if (grid[i][j+1] == 1) ++sused;
                }
                else if (i == gridRowSize-1 && j < gridColSize-1)
                {
                    if (grid[i][j+1] == 1) ++sused;
                }
                else if (j == gridColSize-1 && i < gridRowSize-1)
                {
                    if (grid[i+1][j] == 1) ++sused;
                }
            }
        }
    }
    return island*4 - sused*2;
}

int main(){

    int ar0[] = {0,0,0,0};
    int ar1[] = {0,0,0,0};
    int ar2[] = {0,0,0,0};
    int ar3[] = {0,0,0,1};

    int* a[] = {ar0, ar1, ar2, ar3};

	printf("%d\n", islandPerimeter(a, 4, 4));

	return 0;
}