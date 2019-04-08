#include <stdio.h>
#include <stdlib.h>
#include "gridContainer.h"
#include "cellChecker.h"

// Wypisuje siatke komórek na stdout
void printGrid(grid_t *grid) {
    for(int i = 0; i < grid->sizeY; i++) {
        for(int j = 0; j < grid->sizeX; j++)
            printf(" %c", grid->grid[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Funkcja testowa! Wypisuje liczbe sasiadow wszystkich komorek w tablicy
void printNeighbours(grid_t* grid, stats_t* stats) {
    printf("======SASIEDZI======\n");
    for(int i = 0; i < grid->sizeY; i++) {
        for(int j = 0; j < grid->sizeX; j++)
           printf(" %d", countNeighbours(j, i, grid, stats));
        printf("\n");
    }
    printf("\n");
}

// Zwalnia pamiec po strukturze grid_t
/*void freeGrid(grid_t* grid) {
    for(int i = 0; i < grid->sizeX; i++)
        free(grid->tmp[i]);
    free(grid->tmp);

    for(int i = 0; i < grid->sizeX; i++)
        free(grid->grid[i]);
    free(grid->grid);

    free(grid);
}*/

