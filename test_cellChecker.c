#include <stdio.h>
#include <stdlib.h>
#include "cellChecker.h"
#include "gridContainer.h"
#include "StatisticsContainer.h"

int main(int argc, char** argv){
	stats_t* stats = (stats_t*)malloc(sizeof(stats_t));
	stats->totalDeaths = 0;
	stats->totalCreations = 0;
	grid_t* grid = (grid_t*)malloc(sizeof(grid_t));
	grid->sizeX = 3;
	grid->sizeY = 3;
	grid->grid = (char**)malloc(sizeof(char*) * grid->sizeX);
    	for(int i = 0; i < grid->sizeX; i++)
        	grid->grid[i] = (char*)malloc(sizeof(char) * grid->sizeY);
/* tworzę siatkę 1 0 0
 * 		 1 1 0
 * 		 0 0 0
 * i sprawdzam poprawność komórki środkowej*/	
	int flag;
	grid->grid[0][0] = '1';
	grid->grid[0][1] = '0';
	grid->grid[0][2] = '0';
	grid->grid[1][0] = '1';
	grid->grid[1][1] = '1';
	grid->grid[1][2] = '0';
	grid->grid[2][0] = '0';
	grid->grid[2][1] = '0';
	grid->grid[2][2] = '0';
	if(!(checkState(1,1,grid,stats) == '1' && stats->totalDeaths == 0 && stats->totalCreations == 0)){
		printf("Test wykonał się niepoprawnie\n");
		free(stats);
		for(int i = 0; i < grid->sizeX; i++)
                	free(grid->grid[i]);
		free(grid->grid);
		free(grid);
		return -1;
	}
/* tworzę siatkę 1 0 0
 *               0 1 0
 *               0 0 0
 * i sprawdzam poprawność komórki środkowej*/

	grid->grid[0][0] = '1';
        grid->grid[0][1] = '0';
        grid->grid[0][2] = '0';
        grid->grid[1][0] = '0';
        grid->grid[1][1] = '1';
        grid->grid[1][2] = '0';
        grid->grid[2][0] = '0';
        grid->grid[2][1] = '0';
        grid->grid[2][2] = '0';
	if(!(checkState(1,1,grid,stats) == '0' && stats->totalDeaths == 1 && stats->totalCreations == 0))
                printf("Test wykonał się niepoprawnie\n");
        else
                printf("Test wykonał się poprawnie\n");
	for(int i = 0; i < grid->sizeX; i++)
		free(grid->grid[i]);
        free(grid->grid);
        free(grid);

	return 0;
}
