#ifndef GRIDCONTAINER_H_INCLUDED
#define GRIDCONTAINER_H_INCLUDED

typedef struct {
    char** grid; // grid[y][x]
    char** tmp;
    int sizeX;
    int sizeY;
} grid_t;

void printGrid(grid_t*);

void freeGrid(grid_t*);

#endif // GRIDCONTAINER_H_INCLUDED
