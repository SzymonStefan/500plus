#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include "gridContainer.h"

int main(int argc, char** argv){
	grid_t* grid = createGrid("testowe_dane.txt");
	if(grid->sizeX != 4 || grid->sizeY != 3){
		printf("Błąd w określaniu wymiarów siatki\n");
		return -1;
		for(int i = 0; i < grid->sizeX; i++)
        		free(grid->tmp[i]);
    		free(grid->tmp);
		
    		for(int i = 0; i < grid->sizeX; i++)
        		free(grid->grid[i]);
    		free(grid->grid);
		free(grid);
	}
	if(grid->grid[0][0] != '1' || grid->grid[0][1] != '0' || grid->grid[0][2] != '1' || grid->grid[0][3] != '0' || 
	   grid->grid[1][0] != '1' || grid->grid[1][1] != '1' || grid->grid[1][2] != '1' || grid->grid[1][3] != '1' ||
	   grid->grid[2][0] != '0' || grid->grid[2][1] != '0' || grid->grid[2][2] != '0' || grid->grid[2][3] != '0'){
		printf("Błąd przy przypisywaniu wartości komórką\n");
		return -1;
		for(int i = 0; i < grid->sizeX; i++)
                        free(grid->tmp[i]);
                free(grid->tmp);

                for(int i = 0; i < grid->sizeX; i++)
                        free(grid->grid[i]);
                free(grid->grid);
                free(grid);

	}
	printf("Test wykonał się poprawnie\n");
	for(int i = 0; i < grid->sizeX; i++)
                free(grid->tmp[i]);
        free(grid->tmp);

        for(int i = 0; i < grid->sizeX; i++)
                free(grid->grid[i]);
	free(grid->grid);
	free(grid);

	return 0;



}
