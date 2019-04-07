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
    int scale = 4;



    unsigned char* image = malloc(sizeof(char) * grid->sizeX * grid->sizeY * 4 * scale);
    int i = 0;

    for(int y = 0; y < grid->sizeY; y++) {
        for(int x = 0; x < grid->sizeX; x++) {
            if(grid->grid[y][x] == '1') {
                for(int j = 0; j < scale; j++) {
                    for(int k = 0; k < scale; k++) {
                        image[i] = 0;
                        image[i+1] = 0;
                        image[i+2] = 0;
                        image[i+3] = 255;
                        //printf(" 1");
                    }
                    i+=4;
                }
            }
            else {
                for(int j = 0; j < scale; j++) {
                    image[i++] = 255;
                    image[i++] = 255;
                    image[i++] = 255;
                    image[i++] = 255;
                    //printf(" 0");
                }
            }
        }
        //printf("\n");
    }
    //printf("=============================\n");

    lodepng_encode32_file(fileName, image, grid->sizeX*scale, grid->sizeY);
    free(image);
}
