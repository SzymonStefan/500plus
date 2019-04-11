#include <stdio.h>
#include <stdlib.h>
#include "fileReader.h"
#include "gridContainer.h"

#define ALIVE '1'
#define DEAD '0'

grid_t* createGrid(char* path)
{
    // Otworzenie pliku z danymi
    FILE *in = fopen(path, "r");
    if(in == NULL) {
        printf("Nie udalo sie otworzyc pliku %s!\n", path);
        exit(1);
    }

    // Utworzenie struktury grid_t i alokacja pamieci
    grid_t* grid = (grid_t*) malloc(sizeof(grid_t));
    if(grid == NULL)
        printf("Blad alokacji pamieci na strukture grid_t!\n");

    // Wczytanie wymiarow siatki (sizeX, sizeY)
    grid->sizeX = 0;
    grid->sizeY = 0;

    fscanf(in, "%d %d", &grid->sizeX, &grid->sizeY);
    if(grid->sizeX < 3 || grid->sizeY < 3) {
        printf("Bledny wymiar siatki (x=%d,y=%d)! Wymiary musza byc wieksze od 2.\n ", grid->sizeX, grid->sizeY);
        exit(1);
    }
    printf("Wczytane wymiary siatki: x=%d, y=%d.\n", grid->sizeX, grid->sizeY);

    // Alokacja pamieci na tablice komorek (grid_t->grid)
    grid->grid = (char**)malloc(sizeof(char*) * grid->sizeX);
    for(int i = 0; i < grid->sizeX; i++)
        grid->grid[i] = (char*)malloc(sizeof(char) * grid->sizeY);

    // Wczytanie siatki komorek
    int errors = 0;
    int num = 0;
    for(int i = 0; i < grid->sizeY; i++)
        for(int j = 0; j < grid->sizeX; j++) {
            fscanf(in, "%s", &grid->grid[i][j]);
            num++;
            if(grid->grid[i][j] != ALIVE && grid->grid[i][j] != DEAD) {
                printf("Bledna wartosc komorki na pozycji (%d,%d), rowna \"%c\". Przyjmowane wartosci to 0 lub 1.\n", i, j, grid->grid[i][j]);
                errors++;
            }
        }

    // Wyswietlenie komunikatu po wczytaniu komorek
    if(errors > 0) {
        printf("\nLiczba bledow znalezionych w pliku: %d. Program konczy dzialanie.\n", errors);
        exit(1);
    }
    if(num != grid->sizeX*grid->sizeY){
        printf("Podano nieodpowiednia iloœæ komorek!");
        exit(1);
    }
    else
        printf("\nPoprawnie wczytano stany %d komorek. :)\n", grid->sizeX * grid->sizeY);

    //Stworzenie drugiej tablicy uzywanej do liczenia sasiadow
    grid->tmp = (char**)malloc(sizeof(char*) * grid->sizeX);
    for(int i = 0; i < grid->sizeX; i++)
        grid->tmp[i] = (char*)malloc(sizeof(char) * grid->sizeY);

    fclose(in);
    return grid;
}
