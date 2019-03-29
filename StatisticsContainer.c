#include <stdio.h>
#include "StatisticsContainer.h"

void printStats(stats_t* stats){
    printf("Calkowita liczba smierci %d", stats->totalDeaths);
    printf("Calkowita liczba kreacji %d", stats->totalCreations);
    printf("Calkowita liczba generacji %d", stats->numOfGenerations);
}
