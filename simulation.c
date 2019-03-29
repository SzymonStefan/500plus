#include "simulation.h"
#include "StatisticsContainer.h"
#include <stdlib.h>

options_t* createOptions()
{
    // Utworzenie struktury options_t i alokacja pamieci
    options_t* options = (options_t*) malloc(sizeof(options_t));

    // Ustawienie wartosci domyslnych
    options->name = "Gra";
    options->file = "";
    options->steps = 200;
    options->saveEvery = 20;
    options->stats = 0;

    return options;
}

void nextGeneration(grid_t* grid, stats_t* stats){
    for(int i=0; i<grid->sizeY; i++)
        for(int j=0; j<grid->sizeX; j++){
            grid->tmp[i][j]= checkState(i, j, grid, stats);
                    }
    char** buf = grid->grid;
    grid->grid = grid->tmp;
    grid->tmp = buf;
}
void simulator(grid_t* grid, stats_t* stats, options_t* options){
    for(int i=0; i< options->steps; i++) {
        nextGeneration(grid, stats);
        //if(i % options->saveEvery == 0)
            //createPNG();
    }
}
