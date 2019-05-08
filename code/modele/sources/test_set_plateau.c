#include "test_set_plateau.h"

static int group_setup(void** state){
    Partie* partie = init_partie();
    if(partie == NULL){
        return -1;
    }
    Plateau* p = partie->plateau;
    if(p == NULL){
        return -1;
    }
    p->t->s[0].i = COLONIE;
    Joueur* j = init_joueur(BLANC,"manu");
    p->t->s[0].owner = j;
    (*state) = p;
    add_joueur(j,partie);
    *state = partie;
    return 0;
}

static int group_teardown(void** state){
    free_partie((*state));
    return 0;
}

static void test_setVoleur_coordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(setVoleur(p,0,0),0);
    assert_int_equal(setVoleur(p,1,0),0);
    assert_int_equal(setVoleur(p,2,0),0);
    assert_int_equal(setVoleur(p,1.5,-1),0);
    assert_int_equal(deplacementPlateau(p->plateau,1.5,-1)->t->brigand,1);
    assert_int_equal(p->plateau->t->brigand,0);
    assert_int_equal(setVoleur(p,0,0),0);
    assert_int_equal(deplacementPlateau(p->plateau,1.5,-1)->t->brigand,0);
}

static void test_setVoleur_partieNull(void** state){
    assert_int_equal(setVoleur(NULL,2,0),-1);
}

static void test_setVoleur_coordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(setVoleur(p,10,10),-1);
}

static void test_setRoute_partieNULL(void ** state){
    assert_int_equal(setRoute(NULL,0,0,0),-1);
    assert_int_equal(setRouteFree(NULL,0,0,0),-1);
}

static void test_setRoute_coordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(setRouteFree(p,-10,5,0),-1);
    assert_int_equal(setRouteFree(p,0.5,0.5,0),-1);
    assert_int_equal(setRouteFree(p,0,0,6),-1);
    assert_int_equal(setRouteFree(p,0,0,-3),-1);
    assert_int_equal(setRouteFree(p,0.5,0.5,-1),-1);
}

static void test_setRoute_coordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    Joueur* j = p->joueurs->current->joueur;
    assert_int_equal(setRoute(p,0,0,0),-1);
    assert_int_equal(setRouteFree(p,0,2,1),-1);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    assert_int_equal(setRoute(p,0,0,0),0);
    assert_int_equal(setRoute(p,0,0,0),-1);
    assert_int_equal(setRoute(p,-0.5,-1,1),0);
    assert_int_equal(setRoute(p,-0.5,1,5),0);
    assert_int_equal(setRoute(p,0,0,5),0);
    assert_int_equal(setRoute(p,0,0,1),0);
    deplacementPlateau(p->plateau,1.5,1)->t->a[2].i=ROUTE;
    deplacementPlateau(p->plateau,1.5,1)->t->a[2].owner=j;
    deplacementPlateau(p->plateau,1.5,1)->t->a[3].i=ROUTE;
    deplacementPlateau(p->plateau,1.5,1)->t->a[3].owner=j;
    assert_int_equal(setRoute(p,1,2,3),0);
    assert_int_equal(setRoute(p,2,0,2),0);
}

static void test_setRoute_JoueurDiff(void** state){
    Partie* p = (Partie*) (*state);
    Joueur* j = init_joueur(ROUGE,"remi");
    add_joueur(j,p);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    p->joueurs->current=p->joueurs->current->next;
    assert_int_equal(setRoute(p,0,0,4),-1);
}

static void test_setColonie_partieNULL(void** state){
    assert_int_equal(setColonie(NULL,0,0,0),-1);
    assert_int_equal(setColonieFree(NULL,0,0,0),-1);
}

static void test_setColonie_CoordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(setColonieFree(p,5,1,0),-1);
    assert_int_equal(setColonieFree(p,-0.5,0.5,0),-1);
    assert_int_equal(setColonieFree(p,0,0,7),-1);
    assert_int_equal(setColonieFree(p,0,0,-4),-1);
}

static void test_setColonie_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    Joueur* j = p->joueurs->current->joueur;
    p->plateau->t->a[2].i=ROUTE;
    p->plateau->t->a[2].owner=j;
    assert_int_equal(setColonie(p,0,0,2),-1);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(MOUTON,j);
    gain_ressource(BLE,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(MOUTON,j);
    gain_ressource(BLE,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(MOUTON,j);
    gain_ressource(BLE,j);
    gain_ressource(ARGILE,j);
    gain_ressource(BOIS,j);
    gain_ressource(MOUTON,j);
    gain_ressource(BLE,j);
    assert_int_equal(setColonie(p,0,0,0),-1);
    assert_int_equal(setColonie(p,0,0,1),-1);
    assert_int_equal(setColonie(p,0,0,2),0);
    assert_int_equal(setColonie(p,0,0,4),0);
    assert_int_equal(setColonie(p,0,2,0),-1);
    assert_int_equal(setColonie(p,0,2,1),-1);
    assert_int_equal(setColonie(p,0,2,2),-1);
    deplacementPlateau(p->plateau,0,-2)->t->a[5].i = ROUTE;
    deplacementPlateau(p->plateau,0,-2)->t->a[5].owner = j;
    assert_int_equal(setColonie(p,0,-2,5),0);
    deplacementPlateau(p->plateau,1,0)->t->a[5].i = ROUTE;
    deplacementPlateau(p->plateau,1,0)->t->a[5].owner = j;
    assert_int_equal(setColonie(p,1.5,-1,0),0);
}

static void test_setColonie_JoueurDiff(void** state){
    Partie* p = (Partie*) (*state);
    p->joueurs->current = p->joueurs->current->next;
    assert_int_equal(setColonie(p,0,0,4),-1);
    p->joueurs->current = p->joueurs->current->next;
}

static void test_setVille_partieNULL(void** state){
    assert_int_equal(setVille(NULL,0,0,0), -1);
    assert_int_equal(setVilleFree(NULL,0,0,0),-1);
}

static void test_setVille_CoorFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(setVilleFree(p,-4,3,5),-1);
    assert_int_equal(setVilleFree(p,0.5,1.5,0),-1);
    assert_int_equal(setVilleFree(p,0,0,7),-1);
    assert_int_equal(setVilleFree(p,0,0,-4),-1);
}

static void test_setVille_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    Joueur* j = p->joueurs->current->joueur;
    assert_int_equal(setVilleFree(p,2,0,0),-1);
    assert_int_equal(setVille(p,0,0,0),-1);
    gain_ressource(PIERRE,j);
    gain_ressource(PIERRE,j);
    gain_ressource(PIERRE,j);
    gain_ressource(BLE,j);
    gain_ressource(BLE,j);
    assert_int_equal(setVille(p,0,0,0),0);
    gain_ressource(PIERRE,j);
    gain_ressource(PIERRE,j);
    gain_ressource(PIERRE,j);
    gain_ressource(BLE,j);
    gain_ressource(BLE,j);
    p->plateau->adjacence[3]->adjacence[3]->t->s[5].i = COLONIE;
    p->plateau->adjacence[3]->adjacence[3]->t->s[5].owner = p->joueurs->current->joueur;
    assert_int_equal(setVille(p,1,-2,5),0);
}


int main_set_plateau_test(void){
        const struct CMUnitTest tests_set_plateau[] = {
        cmocka_unit_test(test_setVoleur_coordBonnes),
        cmocka_unit_test(test_setVoleur_coordFausses),
        cmocka_unit_test(test_setVoleur_partieNull),
        cmocka_unit_test(test_setRoute_partieNULL),
        cmocka_unit_test(test_setRoute_coordFausses),
        cmocka_unit_test(test_setRoute_coordBonnes),
        cmocka_unit_test(test_setRoute_JoueurDiff),
        cmocka_unit_test(test_setColonie_partieNULL),
        cmocka_unit_test(test_setColonie_CoordFausses),
        cmocka_unit_test(test_setColonie_CoordBonnes),
        cmocka_unit_test(test_setColonie_JoueurDiff),
        cmocka_unit_test(test_setVille_partieNULL),
        cmocka_unit_test(test_setVille_CoorFausses),
        cmocka_unit_test(test_setVille_CoordBonnes)

    };
    return cmocka_run_group_tests(tests_set_plateau,group_setup,group_teardown);

}
