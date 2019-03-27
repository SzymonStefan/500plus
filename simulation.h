#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED
//void nextGeneration(GridContainer* grid, StatisticsContainer* stats);
typedef struct {
    char* name;
    char* file;
    int steps;
    int saveEvery;
    int stats;
} options_t;

options_t* createOptions();
#endif // SIMULATION_H_INCLUDED
