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

    *state= joueur_1;
    return 0;

}

static int setup_joueur_ressource (void** state){
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;
   joueur_1->ressource[BLE].nb_ressource=0;
   joueur_1->ressource[BOIS].nb_ressource=1;
   joueur_1->ressource[PIERRE].nb_ressource=2;
   joueur_1->ressource[ARGILE].nb_ressource=3;
   joueur_1->ressource[MOUTON].nb_ressource=4;

    *state= joueur_1;
    return 0;

}

static int setup_joueur_achat_route (void** state){
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;

   joueur_1->ressource[BOIS].nb_ressource=2;
   joueur_1->ressource[ARGILE].nb_ressource=2;


    *state= joueur_1;
    return 0;

}

static int setup_joueur_achat_colonie (void** state){
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;

   joueur_1->ressource[BLE].nb_ressource=2;
   joueur_1->ressource[BOIS].nb_ressource=2;
   joueur_1->ressource[ARGILE].nb_ressource=2;
   joueur_1->ressource[MOUTON].nb_ressource=2;


    *state= joueur_1;
    return 0;

}

static int setup_joueur_achat_ville (void** state){
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;

   joueur_1->ressource[BLE].nb_ressource=5;
   joueur_1->ressource[PIERRE].nb_ressource=6;

    *state= joueur_1;
    return 0;

}

static int setup_joueur_achat_cartedev (void** state){
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;

   joueur_1->ressource[BLE].nb_ressource=2;
   joueur_1->ressource[PIERRE].nb_ressource=4;
   joueur_1->ressource[MOUTON].nb_ressource=2;
    *state= joueur_1;
    return 0;

}

static int setup_joueur_cartedev (void** state){
    Couleur couleur_joueur_1;
    char* pseudo_joueur_1;

    couleur_joueur_1=ROUGE;
    pseudo_joueur_1 = "Joueur1";
    Joueur* joueur_1=init_joueur(couleur_joueur_1, pseudo_joueur_1);
    if(joueur_1==NULL)
        return -1;
   joueur_1->carte_dev[MONOPOLE].nb_carte=0;
   joueur_1->carte_dev[CHEVALIER].nb_carte=1;
   joueur_1->carte_dev[ROUTES].nb_carte=2;
   joueur_1->carte_dev[POINT].nb_carte=3;
   joueur_1->carte_dev[DECOUVERTE].nb_carte=4;

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

static void test_dec_score(void **state)
{
    Joueur* joueur_1= *state;
    joueur_1->score = 5;
    dec_score(joueur_1,3);
    assert_int_equal(2, get_score(joueur_1));
}


static void test_get_pseudo(void **state)
{
    Joueur* joueur_1= *state;
    char* pseudo= get_pseudo(joueur_1);
    assert_string_equal("Joueur1", pseudo);
}
static void test_get_nbressource_ptr_NULL(void** state)
{
    Joueur* joueur= NULL;
    assert_int_equal(get_nbressource(PIERRE,joueur),-1);
}
static void test_get_nbressource(void ** state)
{
    Joueur* joueur_1= *state;
    assert_int_equal(get_nbressource(BLE,joueur_1),0);
}

static void test_gain_ressource(void **state)
{
    int nb;
    Joueur* joueur_1= *state;

    gain_ressource(BLE,joueur_1);
    nb=get_nbressource(BLE,joueur_1);
    assert_int_equal(1,nb);

    gain_ressource(BOIS,joueur_1);
    nb=get_nbressource(BOIS,joueur_1);
    assert_int_equal(2,nb);

    gain_ressource(PIERRE,joueur_1);
    nb=get_nbressource(PIERRE,joueur_1);
    assert_int_equal(3,nb);

    gain_ressource(ARGILE,joueur_1);
    nb=get_nbressource(ARGILE,joueur_1);
    assert_int_equal(4,nb);

    gain_ressource(MOUTON,joueur_1);
    nb=get_nbressource(MOUTON,joueur_1);
    assert_int_equal(5,nb);
}

static void test_perte_ressource(void **state)
{
    int nb;
    Joueur* joueur_1= *state;

    perte_ressource(BLE,joueur_1);
    nb=get_nbressource(BLE,joueur_1);
    assert_int_equal(0,nb);

    perte_ressource(BOIS,joueur_1);
    nb=get_nbressource(BOIS,joueur_1);
    assert_int_equal(0,nb);

    perte_ressource(PIERRE,joueur_1);
    nb=get_nbressource(PIERRE,joueur_1);
    assert_int_equal(1,nb);

    perte_ressource(ARGILE,joueur_1);
    nb=get_nbressource(ARGILE,joueur_1);
    assert_int_equal(2,nb);

    perte_ressource(MOUTON,joueur_1);
    nb=get_nbressource(MOUTON,joueur_1);
    assert_int_equal(3,nb);
}


static void test_set_status(void **state)
{
    Joueur* joueur_1= *state;
    set_status(joueur_1, JOUE);
    Status status =get_status(joueur_1);
    assert_int_equal(0,(int*)status);
}
static void test_get_nbcartedev_ptr_NULL(void** state)
{
    Joueur* joueur= NULL;
    assert_int_equal(get_cartedev(MONOPOLE,joueur),-1);
}
static void test_get_nbcartedev(void ** state)
{
    Joueur* joueur_1= *state;
    assert_int_equal(get_cartedev(MONOPOLE,joueur_1),0);
}
static void test_gain_cartedev(void **state)
{
    int nb;
    Joueur* joueur_1= *state;

    gain_cartedev(MONOPOLE,joueur_1);
    nb=get_cartedev(MONOPOLE,joueur_1);
    assert_int_equal(1,nb);

    gain_cartedev(CHEVALIER,joueur_1);
    nb=get_cartedev(CHEVALIER,joueur_1);
    assert_int_equal(2,nb);

    gain_cartedev(ROUTES,joueur_1);
    nb=get_cartedev(ROUTES,joueur_1);
    assert_int_equal(3,nb);

    gain_cartedev(POINT,joueur_1);
    nb=get_cartedev(POINT,joueur_1);
    assert_int_equal(4,nb);

    gain_cartedev(DECOUVERTE,joueur_1);
    nb=get_cartedev(DECOUVERTE,joueur_1);
    assert_int_equal(5,nb);
}

static void test_perte_cartedev(void **state)
{
    int nb;
    Joueur* joueur_1= *state;

    perte_cartedev(MONOPOLE,joueur_1);
    nb=get_cartedev(MONOPOLE,joueur_1);
    assert_int_equal(0,nb);

    perte_cartedev(CHEVALIER,joueur_1);
    nb=get_cartedev(CHEVALIER,joueur_1);
    assert_int_equal(0,nb);

    perte_cartedev(ROUTES,joueur_1);
    nb=get_cartedev(ROUTES,joueur_1);
    assert_int_equal(1,nb);

    perte_cartedev(POINT,joueur_1);
    nb=get_cartedev(POINT,joueur_1);
    assert_int_equal(2,nb);

    perte_cartedev(DECOUVERTE,joueur_1);
    nb=get_cartedev(DECOUVERTE,joueur_1);
    assert_int_equal(3,nb);

}

static void test_get_nb_total_ressource(void** state)
{
    Joueur* joueur= *state;
    assert_int_equal(10,get_nbressource_total(joueur));
}

static void test_achat_route(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_route(joueur1));
    assert_int_equal(0,achat_route(joueur1));
    assert_int_equal(-1,achat_route(joueur1));
}

static void test_achat_colonie(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_colonie(joueur1));
    assert_int_equal(0,achat_colonie(joueur1));
    assert_int_equal(-1,achat_colonie(joueur1));
}


static void test_achat_ville(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_ville(joueur1));
    assert_int_equal(0,achat_ville(joueur1));
    assert_int_equal(-1,achat_ville(joueur1));
}

static void test_achat_cartedev(void** state)
{
    Joueur* joueur1= *state;
    assert_int_equal(0,achat_cartedev(joueur1));
    assert_int_equal(0,achat_cartedev(joueur1));
    assert_int_equal(-1,achat_cartedev(joueur1));
}
static void test_voleur_perte_ressource(void** state)
{
    Joueur* joueur1=*state;
    int flag = voleur_perte_ressource(joueur1);
    int nbcartes= get_nbressource_total(joueur1);
    assert_int_equal(0,flag);
    assert_int_equal(5,nbcartes);
    flag = voleur_perte_ressource(joueur1);
    nbcartes= get_nbressource_total(joueur1);
    assert_int_equal(-1,flag);
    assert_int_equal(5,nbcartes);
}
static void test_get_nbChevalier_ptr_NULL(void** state)
{
    Joueur* joueur1=NULL;
    assert_int_equal(get_nbChevalier(joueur1),-1);
}
static void test_get_nbChevalier(void** state)
{
    Joueur* joueur1=*state;
    assert_int_equal(get_nbChevalier(joueur1),0);
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
        cmocka_unit_test_setup_teardown(test_dec_score,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_get_pseudo,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbressource,setup_joueur_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbressource_ptr_NULL,setup_joueur_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_gain_ressource,setup_joueur_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_perte_ressource,setup_joueur_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_get_nb_total_ressource,setup_joueur_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_set_status,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbcartedev_ptr_NULL,setup_joueur_cartedev,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbcartedev,setup_joueur_cartedev,teardown),
        cmocka_unit_test_setup_teardown(test_gain_cartedev,setup_joueur_cartedev,teardown),
        cmocka_unit_test_setup_teardown(test_perte_cartedev,setup_joueur_cartedev,teardown),
        cmocka_unit_test_setup_teardown(test_achat_route,setup_joueur_achat_route,teardown),
        cmocka_unit_test_setup_teardown(test_achat_colonie,setup_joueur_achat_colonie,teardown),
        cmocka_unit_test_setup_teardown(test_achat_ville,setup_joueur_achat_ville,teardown),
        cmocka_unit_test_setup_teardown(test_achat_cartedev,setup_joueur_achat_cartedev,teardown),
        cmocka_unit_test_setup_teardown(test_voleur_perte_ressource,setup_joueur_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbChevalier_ptr_NULL,setup_joueur,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbChevalier,setup_joueur,teardown),
        };
    return cmocka_run_group_tests(tests_joueur,NULL,NULL);
}
