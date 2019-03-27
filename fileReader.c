#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include "gridContainer.h"
grid_t* createGrid(char* path)
{
    // Otwarcie pliku z danymi
    FILE *in = fopen(path, "r");
    if(in == NULL)
        printf("Blad otwarcia pliku!\n");

    // Utworzenie struktury grid_t i alokacja pamieci
    grid_t* grid = (grid_t*) malloc(sizeof(grid_t));
    if(grid == NULL)
        printf("Blad alokacji pamieci na grid_t grid!\n");

    // Wczytanie wymiarow siatki (sizeX, sizeY)
    grid->sizeX = 0;
    grid->sizeY = 0;

    fscanf(in, "%d %d", &grid->sizeX, &grid->sizeY);
    if(grid->sizeX < 3 || grid->sizeY < 3)
        printf("Bledny wymiar siatki!\n");
    printf("Wczytane X=%d, Y=%d\n", grid->sizeX, grid->sizeY);

    // Alokacja pamieci na tablice komorek (grid_t->grid)
    grid->grid = (char**)malloc(sizeof(char*) * grid->sizeX);
    for(int i = 0; i < grid->sizeY; i++)
        grid->grid[i] = (char*)malloc(sizeof(char) * grid->sizeY);

    // Wczytanie siatki komorek
    for(int i = 0; i < grid->sizeY; i++)
        for(int j = 0; j < grid->sizeX; j++)
            fscanf(in, "%s", &grid->grid[i][j]);

    // Wyswietlenie siatki na stdout
    printf("Wczytana siatka:\n");



    fclose(in);
    return grid;
}
