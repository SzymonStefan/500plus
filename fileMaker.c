#include <stdio.h>
#include <stdlib.h>
#include "StatisticsContainer.h"
#include "simulation.h"
#include "lodepng.h"

// Zapisuje statystyki do pliku
void saveStats(stats_t* stats, options_t* options) {
    FILE *out = fopen("stats.txt", "w");
    if(out == NULL)
        printf("Nie udalo sie zapisac statystyk!\n");
    fprintf(out, "Statystyki dzialania symulacji o nazwie \"%s\"\n", options->name);
    fprintf(out, "===================================================================\n");
    fprintf(out, "Liczba generacji: %d\n", stats->numOfGenerations);
    fprintf(out, "Calkowita liczba \"narodzin\" komorek: %ld\n", stats->totalCreations);
    fprintf(out, "Calkowita liczba \"smierci\" komorek: %ld\n", stats->totalDeaths);

    fclose(out);
}

void savePNG(grid_t* grid, char* fileName) {
    // stworzenie tablicy przechowujacej kolory pikseli do zapisania
    unsigned char* image = malloc(sizeof(char) * grid->sizeX * grid->sizeY * 4);

    // Przepisanie tablicy grid na format wymagany przez funkcje z biblioteki lodepng
    int i = 0;
    for(int y = 0; y < grid->sizeY; y++) {
        for(int x = 0; x < grid->sizeX; x++) {
            if(grid->grid[y][x] == '1') {
                for(int n = 0; n < 3; n++) // czarny
                    image[i++] = 0;
                image[i++] = 255;
            }
            else
                for(int n = 0; n < 4; n++) // bialy
                    image[i++] = 255;
        }
    }

    // Zapisanie pliku PNG przy uzyciu funkcji biblioteki lodepng
    lodepng_encode32_file(fileName, image, grid->sizeX, grid->sizeY);

    // Zwolnienie pamieci
    free(image);
}

