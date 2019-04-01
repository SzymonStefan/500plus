#ifndef STATISTICSCONTAINER_H_INSCLUDED
#define STATISTICSCONTAINER_H_INSCLUDED
typedef struct {
    long int totalDeaths;
    long int totalCreations;
    int numOfGenerations;
} stats_t;

// Wypisuje statystyki
void printStats(stats_t*);

stats_t* createStats();
#endif // STATISTICSCONTAINER_H_INSCLUDED


