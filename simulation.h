#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
#include "StatisticsContainer.h"
#include "gridContainer.h"

void nextGeneration(grid_t* grid, stats_t* stats);

typedef struct {
    char* name;
    char* file;
    int steps;
    int saveEvery;
    int stats;
} options_t;

options_t* createOptions();

void freeOptions(options_t*);
#endif // SIMULATION_H_INCLUDED
