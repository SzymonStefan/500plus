#ifndef CELLCHECKER_H_INCLUDED
#define CELLCHECKER_H_INCLUDED

#include "gridContainer.h"
#include "StatisticsContainer.h"

char checkState(int, int, grid_t*, stats_t*);

int countNeighbours(int, int, grid_t*, stats_t*);

int cellCheckerTester(stats_t*);
#endif // CELLCHECKER_H_INCLUDED
