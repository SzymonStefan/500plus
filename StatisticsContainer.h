#ifndef STATISTICSCONTAINER_H_INSCLUDED
#define STATISTICSCONTAINER_H_INSCLUDED
typedef struct {
    long int totalDeaths;
    long int totalCreations;
    int numOfGenerations;
} stats_t;

stats_t* createStats();

void freeStats(stats_t*);
#endif // STATISTICSCONTAINER_H_INSCLUDED


