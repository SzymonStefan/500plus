#include "simulation.h"
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
