#ifndef GRIDCONTAINER_H_INCLUDED
#define GRIDCONTAINER_H_INCLUDED
typedef struct {
    char** grid;
    int sizeX;
    int sizeY;
} grid_t;

// Wypisuje siatk� kom�rek na stdout
void printGrid(grid_t*);

#endif // GRIDCONTAINER_H_INCLUDED
