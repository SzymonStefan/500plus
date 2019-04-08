#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simulation.h"
#include "StatisticsContainer.h"

// Tworzy strukture przechowujaca opcje
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

// Przeprowadza jedna generacje symulacji
void nextGeneration(grid_t* grid, stats_t* stats){
    // Sprawdzenie przyszlych stanow kazdej komorki tablicy grid
    for(int i = 0; i <grid->sizeY; i++)
        for(int j = 0; j < grid->sizeX; j++) {
            grid->tmp[i][j] = checkState(j, i, grid, stats);
        }

    // Zamiana wskaznikow grid i tmp
    char** buf = grid->grid;
    grid->grid = grid->tmp;
    grid->tmp = buf;
}

// Przeprowadza glowna czesc symulacji
void simulator(grid_t* grid, stats_t* stats, options_t* options){
    for(int i = 0; i < options->steps; i++) {
        printf("Generacja %d\n", i + 1);
        printGrid(grid);
        if(i % options->saveEvery == 0) {
            // Stworzenie odpowiedniej nazwy pliku PNG
            char name[128];
            strcpy(name, options->name);
            char number[16];
            sprintf(number, "%d", i+1);
            strcat(name, number);
            strcat(name, ".png");

            // Zapisanie pliku PNG
            savePNG(grid, name);
        }
        // Nastepna generacja symulacji
        nextGeneration(grid, stats);
        if(stats != NULL)
            stats->numOfGenerations++;

    }
}

// Zwalnia pamiec po options_t
void freeOptions(options_t* options) {
    free(options);
}
