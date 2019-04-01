#include <stdio.h>
#include "StatisticsContainer.h"

void printStats(stats_t* stats){
    printf("Calkowita liczba smierci %d", stats->totalDeaths);
    printf("Calkowita liczba kreacji %d", stats->totalCreations);
    printf("Calkowita liczba generacji %d", stats->numOfGenerations);
}

stats_t* createStats() {
    stats_t* stats = (stats_t*) malloc(sizeof(stats_t));
    stats->numOfGenerations = 0;
    stats->totalCreations = 0;
    stats->totalDeaths = 0;
    return stats;
}
