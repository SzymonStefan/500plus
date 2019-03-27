#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"
#include "fileReader.h"
//#include "fileMaker.h"

int main()
{
    grid_t *grid = createGrid("g1.txt");
    printGrid(grid);
    printf("%d\n", checkState(1,2,grid));

    return 0;
}
