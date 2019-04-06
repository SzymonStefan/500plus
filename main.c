#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "simulation.h"
#include "fileReader.h"
#include "fileMaker.h"
#include "lodepng.h"


int main(int argc , char** argv)
{


/*
    unsigned char* test = malloc(sizeof(char) * 4);
    //for(int i = 0; i < 16; i++)
        //test[i] = 10*i;
    test[0] = 0;
    test[1] = 0;
    test[2] = 0;
    test[3] = 255;
    lodepng_encode32_file("TEST.png", test, 1, 1);

    free(test);
*/

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
    char flag;
    while ((opt = getopt_long_only(argc, argv, ":", longOptions, &index)) != -1) {
        switch (opt) {
        case 0: // name
            options->name = optarg;
            flag = '*';
            for(int i=0; options->name[i] != '\0'; i++)
                if( ! (isalnum(options->name[i]) || options->name[i] == '_' || options->name[i] == '/' ||  options->name[i] == '.') ){
                    flag = options->name[i];
                    break;
                }
            if(flag != '*'){
                printf("Podano nieodpowiedni znak przy argumencie name \"%c\"\n",flag);
                exit(1);
            }
            break;

        case 1: // file
            options->file = optarg;
            flag = '*';
            for(int i=0; options->file[i] != '\0'; i++)
                if( ! (isalnum(options->file[i]) || options->file[i] == '_' || options->file[i] == '/' || options->file[i] == '.') ){
                    flag = options->file[i];
                    break;
                }
            if(flag != '*'){
                printf("Podano nieodpowiedni znak przy wczytaniu pliku\n");
                exit(1);
            }
            break;

        case 2: // steps
            options->steps = atoi(optarg);
            if(options->steps <= 0){
                printf("Podano nieodpowiedni argument przy steps");
                exit(1);
            }
            break;

        case 3: // save-every
            options->saveEvery = atoi(optarg);
            if(options->saveEvery <= 0){
                printf("Podano nieodpowiedni argument przy saveEvery");
                exit(1);
            }
            break;

        case 4: // stats
            options->stats = 1;
            break;

        case (int)':': // argument bez podanej wartosci
            printf("Podano argument bez jego wartosci!\n");
            break;

        default: // Podano nieznany argument
            printf("Podano nieznany argument!\n");
            break;
        }
    }
    // Jesli brak argumentu -file, program konczy dzialanie
    if(options->file == "") {
        printf("Blad, nie podano pliku z danymi! Prosze uzyc argumentu -file plik.\n");
        exit(1);
    }

    // Wyswietlenie parametrow symulacji
    printf("Parametry symulacji:\n");
    printf(" * Nazwa: %s\n", options->name);
    printf(" * Plik z danymi: %s\n", options->file);
    printf(" * Liczba generacji: %d\n", options->steps);
    printf(" * Zapis obrazka co %d generacji\n", options->saveEvery);
    if(options->stats == 1)
        printf(" * Statystyki: TAK\n\n");
    else
        printf(" * Statystyki: NIE\n\n");

    // Stworzenie struktury przechowujacej siatke komorek
    grid_t *grid = createGrid(options->file);

    // Stworzenie struktury przechowujacej statystyki
    stats_t* stats;
    if(options->stats == 1)
        stats = createStats();
    else
        stats = NULL;

    // Uruchomienie symulacji
    simulator(grid, stats, options);

    // Jesli wybrano taka opcje, generowanie pliku ze statystykami
    if(options->stats == 1) {
        saveStats(stats, options);
        freeStats(stats);
    }

    //freeGrid(grid);
    //freeOptions(options);
    return 0;
}
