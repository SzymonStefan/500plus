#include "cellChecker.h"

// Sprawdza przyszy stan komorki x,y (1 = zywa, 0 = martwa)
char checkState(int x, int y, grid_t* grid, stats_t* stats)
{
    // Liczenie wszystkich zywych komorek w sasiedztwie Moore'a
    int alive = 0;
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++) {
            if(grid->grid[(y + i + grid->sizeY)%grid->sizeY][(x + j + grid->sizeX)%grid->sizeX] == '1')
                alive++;
        }


    // Zwrocenie przyszlego stanu komorki
    if(alive == 3)
        return '1';
    else if(alive == 4)
        return grid->grid[y][x];
    else
        return '0';
}


/* DEBUG */ int countNeighbours(int x, int y, grid_t* grid, stats_t* stats) {
    int alive = 0;
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++) {
            if(grid->grid[(y + i + grid->sizeY)%grid->sizeY][(x + j + grid->sizeX)%grid->sizeX] == '1')
                alive++;
        }
    if(grid->grid[y][x] == '1')
        return alive - 1;
    return alive;
}
