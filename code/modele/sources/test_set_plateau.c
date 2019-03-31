#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include "cmocka_pbc.h"
#include "test_set_plateau.h"
#include "ressource.h"
#include "joueur.h"
#include "get_plateau.h"
#include "set_plateau.h"
#include "plateau.h"

static int group_setup(void** state){
    Plateau* p = initPlateau();
    if(p != NULL){
        p->t->s[0].i = COLONIE;
        p->t->s[0].owner = init_joueur(VERT,"manu");
        (*state) = p;
        return 0;
    }
    return -1;
}

static int group_teardown(void** state){
    freePlateau((*state));
    return 0;
}

static void test_setVoleur_coordBonnes(void** state){
    Plateau* p = (Plateau*) (*state);
    setVoleur(p,1.5,1);
    assert_int_equal(p->t->brigand,0);
    assert_int_equal(deplacementPlateau(p,1.5,1)->t->brigand,1);
}

static void test_setVoleur_PlateauNULL(void** state){
    assert_int_equal(setVoleur(NULL,2,0),-1);
}

static void test_setVoleur_coordFausses(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_int_equal(setVoleur(p,10,10),-1);
}

static void test_setRoute_PlateauNULL(void ** state){
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setRoute(NULL,0,0,0,j),-1);
}

static void test_setRoute_coordFausses(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setRoute(p,-10,5,0,j),-1);
    assert_int_equal(setRoute(p,0.5,0.5,0,j),-1);
    assert_int_equal(setRoute(p,0,0,6,j),-1);
    assert_int_equal(setRoute(p,0.5,0.5,-1,j),-1);
}

static void test_setRoute_JoueurNULL(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_int_equal(setRoute(p,0,0,0,NULL),-1);
}

static void test_setRoute_coordBonnes(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(VERT,"manu");
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    assert_int_equal(setRoute(p,0,0,0,j),0);
    assert_int_equal(setRoute(p,0,0,0,j),-1);
    assert_int_equal(setRoute(p,2,0,0,j),-1);
    assert_int_equal(setRoute(p,-1,0,4,j),0);
    assert_int_equal(setRoute(p,-1,0,2,j),0);
}

static void test_setRoute_JoueurDiff(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(ROUGE,"remi");
    assert_int_equal(setRoute(p,-0.5,1,0,j),-1);
    assert_int_equal(setRoute(p,0,0,1,j),-1);

}

static void test_setColonie_PlateauNULL(void** state){
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setColonie(NULL,0,0,0,j),-1);
}

static void test_setColonie_CoordFausses(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setColonie(p,5,1,0,j),-1);
    assert_int_equal(setColonie(p,-0.5,0.5,0,j),-1);
    assert_int_equal(setColonie(p,0,0,7,j),-1);
    assert_int_equal(setColonie(p,0,0,-4,j),-1);
}

static void test_setColonie_JoueurNULL(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_int_equal(setColonie(p,0,0,2,NULL),-1);
}

static void test_setColonie_CoordBonnes(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(VERT,"manu");
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(MOUTON,j);
    gain_ressource(BLE,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(MOUTON,j);
    gain_ressource(BLE,j);

    assert_int_equal(setColonie(p,0,0,0,j),-1);
    assert_int_equal(setColonie(p,0,0,1,j),-1);
    assert_int_equal(setColonie(p,0,2,0,j),-1);
    assert_int_equal(setColonie(p,-1,0,4,j),0);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    setRoute(p,-1,0,5,j);
    setRoute(p,-2,0,4,j);
    setRoute(p,-2,0,5,j);
    assert_int_equal(setColonie(p,-2,0,5,j),0);
}

static void test_setColonie_JoueurDiff(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(ROUGE,"remi");
    Joueur* k = init_joueur(VERT,"manu");
    setRoute(p,0,0,5,k);
    assert_int_equal(setColonie(p,0,0,4,j),-1);
}

static void test_setVille_PlateauNULL(void** state){
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setVille(NULL,0,0,0,j), -1);
}

static void test_setVille_CoorFausses(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setVille(p,-4,3,5,j),-1);
    assert_int_equal(setVille(p,0.5,1.5,0,j),-1);
    assert_int_equal(setVille(p,0,0,7,j),-1);
    assert_int_equal(setVille(p,0,0,-4,j),-1);
}

static void test_setVille_JoueurNULL(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_int_equal(setVille(p,0,0,0,NULL),-1);
}

static void test_setVille_CoordBonnes(void** state){
    Plateau* p = (Plateau*) (*state);
    Joueur* j = init_joueur(VERT,"manu");
    assert_int_equal(setVille(p,2,0,0,j),-1);
    assert_int_equal(setVille(p,0,0,0,j),-1);
    gain_ressource(PIERRE,j);
    gain_ressource(PIERRE,j);
    gain_ressource(PIERRE,j);
    gain_ressource(BLE,j);
    gain_ressource(BLE,j);
    assert_int_equal(setVille(p,0,0,0,j),0);
}


int main_set_plateau_test(void){
        const struct CMUnitTest tests_set_plateau[] = {
        cmocka_unit_test(test_setVoleur_coordBonnes),
        cmocka_unit_test(test_setVoleur_coordFausses),
        cmocka_unit_test(test_setVoleur_PlateauNULL),
        cmocka_unit_test(test_setRoute_PlateauNULL),
        cmocka_unit_test(test_setRoute_coordFausses),
        cmocka_unit_test(test_setRoute_JoueurNULL),
        cmocka_unit_test(test_setRoute_coordBonnes),
        cmocka_unit_test(test_setRoute_JoueurDiff),
        cmocka_unit_test(test_setColonie_PlateauNULL),
        cmocka_unit_test(test_setColonie_CoordFausses),
        cmocka_unit_test(test_setColonie_JoueurNULL),
        cmocka_unit_test(test_setColonie_CoordBonnes),
        cmocka_unit_test(test_setColonie_JoueurDiff),
        cmocka_unit_test(test_setVille_PlateauNULL),
        cmocka_unit_test(test_setVille_CoorFausses),
        cmocka_unit_test(test_setVille_JoueurNULL),
        cmocka_unit_test(test_setVille_CoordBonnes)

    };
    return cmocka_run_group_tests(tests_set_plateau,group_setup,group_teardown);

}
