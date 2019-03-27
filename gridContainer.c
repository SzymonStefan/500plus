#include <stdio.h>
#include "gridContainer.h"

void printGrid(grid_t *grid)
{
    for(int i = 0; i < grid->sizeY; i++) {
        for(int j = 0; j < grid->sizeX; j++)
            printf("%c ", grid->grid[i][j]);
        printf("\n");
    }
    printf("\n");
}
