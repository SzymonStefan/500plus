#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "simulation.h"
#include "fileReader.h"
//#include "fileMaker.h"

int main(int argc , char** argv)
{
    // Stworzenie struktury przechowujacej opcje programu
    options_t* options = createOptions();

    int opt;
    int index = 0; // indeks tablicy longOptions

    // struktura z informacjami o argumentach dla getopt
    static struct option longOptions[] = {
        {"name",        required_argument,  0,  0 },
        {"file",        required_argument,  0,  1 },
        {"steps",       required_argument,  0,  2 },
        {"save-every",  required_argument,  0,  3 },
        {"stats",       no_argument,        0,  4 },
        {0,             0,                  0,  0 }
    };

    // Petla odczytujaca wszystkie argumenty przy pomocy getopt
    while ((opt = getopt_long_only(argc, argv, ":", longOptions, &index)) != -1) {
        switch (opt) {
        case 0: // name
            options->name = optarg;
            break;
        case 1: // file
            options->file = optarg;
            break;
        case 2: // steps
            options->steps = atoi(optarg);
            break;
        case 3: // save-every
            options->saveEvery = atoi(optarg);
            break;
        case 4: // stats
            options->stats = 1;
            break;
        case (int)':': // argument bez podanej wartosci
            printf("Podano argument bez jego wartosci!\n");
            break;

        // Podano nieznany argument
        default:
            printf("Podano nieznany argument!\n");
            break;
        }

    }
    // Jesli brak argumentu -file, program konczy dzialanie
    if(options->file == "") {
        printf("Blad, nie podano pliku z danymi! Prosze uzyc argumentu -file plik.\n");
        exit(1);
    }

    printf("Argumenty:\n");
    printf(" name: %s\n", options->name);
    printf(" file: %s\n", options->file);
    printf(" steps: %d\n", options->steps);
    printf(" save-every: %d\n", options->saveEvery);
    printf(" stats: %d\n", options->stats);
    printf("-----------------------------------------------------------\n");

    grid_t *grid = createGrid(options->file);
    stats_t* stats = createStats();

    //printNeighbours(grid);


    simulator(grid, stats, options);

    return 0;
}
