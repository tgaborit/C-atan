#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "test_get_plateau.h"
#include "test_set_plateau.h"
#include "test_plateau.h"
#include "UTest-get_partie.h"
#include "UTest-joueur.h"
#include "UTest-set_partie.h"


int main()
{
    main_test();
    main_get_partie_test();
    main_get_plateau_test();
    main_joueur_test();
    main_partie_test();
    main_set_plateau_test();

    return EXIT_SUCCESS;

}



