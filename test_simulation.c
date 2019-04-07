#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"
#include "gridContainer.h"
#include "StatisticsContainer.h"

int main(int argc, char** argv){
	stats_t* stats = NULL;
	options_t* opt = (options_t*)malloc(sizeof(options_t));
	opt->steps = 4;
	opt->name = "Prykład";
	opt->saveEvery = 100;

        grid_t* grid = (grid_t*)malloc(sizeof(grid_t));
        grid->sizeX = 5;
        grid->sizeY = 5;

        grid->grid = (char**)malloc(sizeof(char*) * grid->sizeX);
        for(int i = 0; i < grid->sizeX; i++)
                grid->grid[i] = (char*)malloc(sizeof(char) * grid->sizeY);

	grid->tmp = (char**)malloc(sizeof(char*) * grid->sizeX);
        for(int i = 0; i < grid->sizeX; i++)
                grid->tmp[i] = (char*)malloc(sizeof(char) * grid->sizeY);

/* tworzę siatkę schematu Blinker
 * 		 0 0 0 0 0
 *               0 0 1 0 0
 *               0 0 1 0 0
 *               0 0 1 0 0
 *               0 0 0 0 0 
 * i sprawdzam jej poprawną zmianę*/

        grid->grid[0][0] = '0'; grid->grid[0][1] = '0'; grid->grid[0][2] = '0'; grid->grid[0][3] = '0'; grid->grid[0][4] = '0';
        grid->grid[1][0] = '0'; grid->grid[1][1] = '0'; grid->grid[1][2] = '1'; grid->grid[1][3] = '0'; grid->grid[1][4] = '0';
	grid->grid[2][0] = '0'; grid->grid[2][1] = '0'; grid->grid[2][2] = '1'; grid->grid[2][3] = '0'; grid->grid[2][4] = '0';
	grid->grid[3][0] = '0'; grid->grid[3][1] = '0'; grid->grid[3][2] = '1'; grid->grid[3][3] = '0'; grid->grid[3][4] = '0';
	grid->grid[4][0] = '0'; grid->grid[4][1] = '0'; grid->grid[4][2] = '0'; grid->grid[4][3] = '0'; grid->grid[4][4] = '0';
	simulator(grid,stats,opt);

	//W czwartej generacji stan sietki powinien równać się stanowi początkowemu wybieram więc kilka komórek i porównuje stany
	if(grid->grid[0][0] != '0' || grid->grid[0][4] != '0' || grid->grid[1][2] != '1' || grid->grid[3][2] != '1' || grid->grid[4][3] != '0')
		printf("Program wykonał się niepoprawnie\n");
	else
		printf("Program wykonał się poprawnie\n");
	free(opt);
	free(stats);

	for(int i = 0; i < grid->sizeX; i++)
        	free(grid->tmp[i]);
   	free(grid->tmp);

    	for(int i = 0; i < grid->sizeX; i++)
        	free(grid->grid[i]);
    	free(grid->grid);
	free(grid);
	return 0;
}
