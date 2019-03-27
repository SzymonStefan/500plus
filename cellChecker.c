#include "cellChecker.h"

// Sprawdza przyszy stan komorki x,y (1 = zywa, 0 = martwa)
int checkState(int x, int y, grid_t* grid)
{
    // Liczenie wszystkich zywych komorek w sasiedztwie Moore'a
    int alive = 0;
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++) {
            if(grid->grid[(y + i + grid->sizeY)%grid->sizeY][(x + j + grid->sizeX)%grid->sizeX] == '1')
                alive++;
            printf("%c ", grid->grid[(y + i + grid->sizeY)%grid->sizeY][(x + j + grid->sizeX)%grid->sizeX]);
        }

    // Zwrocenie przyszlego stanu komorki
    if(alive == 3)
        return 1;
    else if(alive == 4)
        return atoi(grid->grid[x][y]);
    else
        return 0;
}
