#include <stdio.h>
#include "statisticsContainer.h"
#include "simulation.h"

// zapisuje statystyki do pliku
void saveStats(stats_t* stats, options_t* options) {
    FILE *out = fopen("stats.txt", "w");
    if(out == NULL)
        printf("Nie udalo sie zapisac statystyk!\n");
    fprintf(out, "Statystyki dzialania symulacji o nazwie \"%s\"\n", options->name);
    fprintf(out, "===================================================================\n");
    fprintf(out, "Liczba generacji: %d\n", stats->numOfGenerations);
    fprintf(out, "Calkowita liczba \"narodzin\" komorek: %d\n", stats->totalCreations);
    fprintf(out, "Calkowita liczba \"smierci\" komorek: %d\n", stats->totalDeaths);

    fclose(out);
}
