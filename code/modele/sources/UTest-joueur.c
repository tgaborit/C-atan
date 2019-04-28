#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "joueur.h"
#include "UTest-joueur.h"

static int setup_joueur (void ** state)
{
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;
   joueur_1->ressource[BLE].nb_ressource=3;
   joueur_1->ressource[ARGILE].nb_ressource=4;
   joueur_1->ressource[PIERRE].nb_ressource=3;
   joueur_1->ressource[BOIS].nb_ressource=6;
   joueur_1->ressource[MOUTON].nb_ressource=1;

    *state= joueur_1;
    return 0;

}
static void test_init_joueur(void ** state)
{
    Joueur* joueur_1=*state;
    assert_int_not_equal(0,(int*)joueur_1);
}
static void test_inc_score(void **state)
{
    Joueur* joueur_1= *state;
    inc_score(joueur_1,2);
    assert_int_equal(2, get_score(joueur_1));
}

static void test_get_pseudo(void **state)
{
    Joueur* joueur_1= *state;
    char* pseudo= get_pseudo(joueur_1);
    assert_string_equal("Joueur1", pseudo);
}

static void test_gain_ressource(void **state)
{
    int nbBois;
    Joueur* joueur_1= *state;
    gain_ressource(BOIS,joueur_1);
    nbBois=get_nbressource(BOIS,joueur_1);
    assert_int_equal(7,nbBois);
}

static void test_perte_ressource(void **state)
{
    int nbBois;
    Joueur* joueur_1= *state;
    perte_ressource(BOIS,joueur_1);
    nbBois=get_nbressource(BOIS,joueur_1);
    assert_int_equal(5,nbBois);
}


static void test_set_status(void **state)
{
    Joueur* joueur_1= *state;
    set_status(joueur_1, JOUE);
    Status status =get_status(joueur_1);
    assert_int_equal(0,(int*)status);
}

static void test_gain_cartedev(void **state)
{
    int nbChevalier;
    Joueur* joueur_1= *state;
    gain_cartedev(CHEVALIER,joueur_1);
    nbChevalier=get_cartedev(CHEVALIER,joueur_1);
    assert_int_equal(1,nbChevalier);
}

static void test_perte_cartedev(void **state)
{
    int nbChevalier;
    Joueur* joueur_1= *state;
    joueur_1->carte_dev[CHEVALIER].nb_carte=2;
    perte_cartedev(BOIS,joueur_1);
    nbChevalier=get_cartedev(CHEVALIER,joueur_1);
    assert_int_equal(1,nbChevalier);
}

static void test_get_nb_total_ressource(void** state)
{
    Joueur* joueur= *state;
    assert_int_equal(17,get_nbressource_total(joueur));
}

static void test_achat_route(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_route(joueur1));
    assert_int_equal(0,achat_route(joueur1));
    assert_int_equal(0,achat_route(joueur1));
    assert_int_equal(0,achat_route(joueur1));
    assert_int_equal(-1,achat_route(joueur1));
}

static void test_achat_colonie(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_colonie(joueur1));
    assert_int_equal(-1,achat_colonie(joueur1));
}


static void test_achat_ville(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_ville(joueur1));
    assert_int_equal(-1,achat_ville(joueur1));
}

static void test_achat_cartedev(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_cartedev(joueur1));
    assert_int_equal(-1,achat_cartedev(joueur1));
}
static int teardown (void ** state)
{
    free_joueur(*state);
    return 0 ;
}

int main_joueur_test(void)
{
    const struct CMUnitTest tests_joueur[]={
        cmocka_unit_test_setup_teardown(test_init_joueur,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_inc_score,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_get_pseudo,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_gain_ressource,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_perte_ressource,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_get_nb_total_ressource,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_set_status,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_gain_cartedev,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_perte_cartedev,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_achat_route,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_achat_colonie,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_achat_ville,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_achat_cartedev,setup_joueur,teardown),
        };
    return cmocka_run_group_tests(tests_joueur,NULL,NULL);
}
