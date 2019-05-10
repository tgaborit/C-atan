

#include "modele/headers/test_get_plateau.h"


static int group_setup(void** state){
    Partie* partie = init_partie();
    if(partie != NULL){
        (*state) = partie;
        return 0;
    }
    return -1;
}

static int infra_setup(void** state){
    Partie* partie = init_partie();
    if(partie == NULL){
        return -1;
    }
    Joueur* manu = init_joueur(BLANC,"manu");
    Joueur* remi = init_joueur(ROUGE,"remi");
    add_joueur(manu,partie);
    add_joueur(remi,partie);
    partie->joueurs->current = partie->joueurs->current->next;
    Plateau* p = partie->plateau;
    p->t->a[2].i = 3;
    p->t->a[2].owner = manu;
    p->adjacence[4]->t->a[0].i = 3;
    p->adjacence[4]->t->a[0].owner = remi;
    p->t->s[2].i = 2;
    p->t->s[2].owner = manu;
    p->adjacence[4]->t->s[0].i = 1;
    p->adjacence[4]->t->s[0].owner = remi;
    (*state) = partie;
    return 0;
}

static int infra_teardown(void** state){
    free_partie(*state);
    return 0;
}

static int group_teardown(void** state){
    free_partie(*state);
    return 0;
}

static void test_getProba_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_not_equal(-1,getProba(p,1,0));
    assert_int_not_equal(-1,getProba(p,-1.5,1));
    assert_int_equal(0,getProba(p,0,0));
}

static void test_getProba_CoordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(-1,getProba(p,-10.5,12));
    assert_int_equal(-1,getProba(p,0.5,0.5));
}

static void test_getProba_partieNull(void** state){
    assert_int_equal(-1,getProba(NULL,0,0));
}

static void test_getType_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_not_equal(-1,getType(p,0,2));
    assert_int_not_equal(-1,getType(p,1.5,-1));
    assert_int_equal(2,getType(p,0,0));
}

static void test_getType_CoorFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(-1,getType(p,-5,3.7));
    assert_int_equal(-1,getType(p,0.5,0.5));
}

static void test_getType_partieNull(void** state){
    assert_int_equal(-1,getType(NULL,0,0));
}

static void test_getVoleur_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(0,getVoleur(p,1,2));
    assert_int_equal(1,getVoleur(p,0,0));
    assert_int_equal(0,getVoleur(p,-1,-2));
}

static void test_getVoleur_CoordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(-1,getVoleur(p,1.7,2));
    assert_int_equal(-1,getVoleur(p,-5,6));
    assert_int_equal(-1,getVoleur(p,-1,-1));
}

static void test_getVoleur_PartieNull(void** state){
    assert_int_equal(-1,getVoleur(NULL,0,0));
}

static void test_getInfrastructureArrete_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(0,getInfrastructureArrete(p,1,0,0));
    assert_int_equal(3,getInfrastructureArrete(p,0,0,2));
    assert_int_equal(3,getInfrastructureArrete(p,0.5,1,0));
}

static void test_getInfrastructureArrete_CoordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(-1,getInfrastructureArrete(p,-5,7,1));
    assert_int_equal(-1,getInfrastructureArrete(p,0.5,0.5,3));
    assert_int_equal(-1,getInfrastructureArrete(p,0.5,0.5,12));
    assert_int_equal(-1,getInfrastructureArrete(p,0,2,-5));
}

static void test_getInfrastructureArrete_partieNull(void** state){
    assert_int_equal(-1,getInfrastructureArrete(NULL,0,0,0));
}

static void test_getJoueurArrete_CoordBonnes(void **state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(0,strcmp("manu",getJoueurArrete(p,0,0,2)->pseudo));
    assert_int_equal(0,strcmp("remi",getJoueurArrete(p,0.5,1,0)->pseudo));
}

static void test_getJoueurArrete_CoordFausses(void **state){
    Partie* p = (Partie*) (*state);
    assert_ptr_equal(NULL,getJoueurArrete(p,2,0,5));
    assert_ptr_equal(NULL,getJoueurArrete(p,0.5,0.5,3));
    assert_ptr_equal(NULL,getJoueurArrete(p,0,0,10));
    assert_ptr_equal(NULL,getJoueurArrete(p,-10,6,-4));
}

static void test_getJoueurArrete_partieNull(void** state){
    assert_ptr_equal(NULL,getJoueurArrete(NULL,0,0,0));
}

static void test_getInfrastructureSommet_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(2,getInfrastructureSommet(p,0,0,2));
    assert_int_equal(1,getInfrastructureSommet(p,0.5,1,0));
}

static void test_getInfrastructureSommet_CoordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(-1,getInfrastructureSommet(p,3,2,4));
    assert_int_equal(-1,getInfrastructureSommet(p,0,0.5,3));
    assert_int_equal(-1,getInfrastructureSommet(p,0.5,0.5,12));
    assert_int_equal(-1,getInfrastructureSommet(p,0,0,10));
}

static void test_getInfrastructureSommet_partieNull(void** state){
    assert_int_equal(-1,getInfrastructureSommet(NULL,0,0,0));
}



static void test_getJoueurSommet_CoordBonnes(void** state){
    Partie* p = (Partie*) (*state);
    assert_int_equal(0,strcmp("manu",getJoueurSommet(p,0,0,2)->pseudo));
    assert_int_equal(0,strcmp("remi",getJoueurSommet(p,0.5,1,0)->pseudo));

}

static void test_getJoueurSommet_CoordFausses(void** state){
    Partie* p = (Partie*) (*state);
    assert_ptr_equal(NULL,getJoueurSommet(p,2,0,5));
    assert_ptr_equal(NULL,getJoueurSommet(p,0.5,0.5,3));
    assert_ptr_equal(NULL,getJoueurSommet(p,0,0,10));
    assert_ptr_equal(NULL,getJoueurSommet(p,-10,6,-4));

}

static void test_getJoueurSommet_partieNull(void** state){
    assert_ptr_equal(NULL,getJoueurSommet(NULL,0,0,0));
}

int main_get_plateau_test(void){
    const struct CMUnitTest tests_get_plateau[] = {
        cmocka_unit_test(test_getProba_CoordBonnes),
        cmocka_unit_test(test_getProba_CoordFausses),
        cmocka_unit_test(test_getProba_partieNull),
        cmocka_unit_test(test_getType_CoordBonnes),
        cmocka_unit_test(test_getType_CoorFausses),
        cmocka_unit_test(test_getType_partieNull),
        cmocka_unit_test(test_getVoleur_CoordBonnes),
        cmocka_unit_test(test_getVoleur_CoordFausses),
        cmocka_unit_test(test_getVoleur_PartieNull),
        cmocka_unit_test_setup_teardown(test_getInfrastructureArrete_CoordBonnes,infra_setup,infra_teardown),
        cmocka_unit_test_setup_teardown(test_getInfrastructureArrete_CoordFausses,infra_setup,infra_teardown),
        cmocka_unit_test(test_getInfrastructureArrete_partieNull),
        cmocka_unit_test_setup_teardown(test_getJoueurArrete_CoordBonnes,infra_setup,infra_teardown),
        cmocka_unit_test_setup_teardown(test_getJoueurArrete_CoordFausses,infra_setup,infra_teardown),
        cmocka_unit_test(test_getJoueurArrete_partieNull),
        cmocka_unit_test_setup_teardown(test_getInfrastructureSommet_CoordBonnes,infra_setup,infra_teardown),
        cmocka_unit_test_setup_teardown(test_getInfrastructureSommet_CoordFausses,infra_setup,infra_teardown),
        cmocka_unit_test(test_getInfrastructureSommet_partieNull),
        cmocka_unit_test_setup_teardown(test_getJoueurSommet_CoordBonnes,infra_setup,infra_teardown),
        cmocka_unit_test_setup_teardown(test_getJoueurSommet_CoordFausses,infra_setup,infra_teardown),
        cmocka_unit_test(test_getJoueurSommet_partieNull)
    };
    return cmocka_run_group_tests(tests_get_plateau,group_setup,group_teardown);
}
