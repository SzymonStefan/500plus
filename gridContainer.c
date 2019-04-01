#include <stdio.h>
#include "gridContainer.h"

/*DEBUG*/ #include "cellChecker.h"

// Wypisuje siatkê komórek na stdout
void printGrid(grid_t *grid)
{
    for(int i = 0; i < grid->sizeY; i++) {
        for(int j = 0; j < grid->sizeX; j++)
            printf(" %c", grid->grid[i][j]);
        printf("\n");
    }
    printf("\n");
}

/*DEBUG*/ void printNeighbours(grid_t* grid, stats_t* stats) {
    printf("======SASIEDZI======\n");
    for(int i = 0; i < grid->sizeY; i++) {
        for(int j = 0; j < grid->sizeX; j++)
           printf(" %d", countNeighbours(j, i, grid, stats));
        printf("\n");
    }
    printf("\n");
}
