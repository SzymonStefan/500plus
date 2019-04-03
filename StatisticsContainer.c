#include <stdio.h>
#include "StatisticsContainer.h"

// Tworzy strukture porzechowujaca statystyki z domyslnymi wartosciami
stats_t* createStats() {
    stats_t* stats = (stats_t*) malloc(sizeof(stats_t));
    stats->numOfGenerations = 0;
    stats->totalCreations = 0;
    stats->totalDeaths = 0;
    return stats;
}

// Czysci pamiec po statystykach
void freeStats(stats_t* stats) {
    free(stats);
}
