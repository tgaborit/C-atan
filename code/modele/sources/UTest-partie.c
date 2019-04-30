#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <cmocka_pbc.h>
#include <string.h>
#include "partie.h"
#include "get_plateau.h"
#include "UTest-partie.h"

static void setOnFirst_list_joueur(List_joueur* list)
{
    list->current=list->first;
}

static int setup_partie (void ** state)
{
        Partie* partie= init_partie();
    if(partie==NULL)
        {
        printf("erreur init partie\n");
        return -1;
        }


    Joueur* joueur_1=init_joueur(ROUGE,"joueur1");
    Joueur* joueur_2=init_joueur(BLEU,"joueur2");
    Joueur* joueur_3=init_joueur(VERT,"joueur3");
    Joueur* joueur_4=init_joueur(ORANGE,"joueur4");

    if (joueur_1==NULL || joueur_2==NULL || joueur_3==NULL || joueur_4==NULL )
        {
        printf("erreur init joueur\n");
        return -1;
        }

    add_joueur(joueur_1,partie);
    add_joueur(joueur_2,partie);
    add_joueur(joueur_3,partie);
    add_joueur(joueur_4,partie);

    partie->joueurs->first->joueur->score=6;
    partie->joueurs->first->next->joueur->score=7;
    partie->joueurs->first->next->next->joueur->score=2;
    partie->joueurs->last->joueur->score=3;

    *state = partie;
    return 0;
}

static void test_get_nb_joueur(void **state)
{
    Partie* partie= *state;
    int c= get_nbjoueurs(partie);
    assert_int_equal(4, c);
}

static void test_donner_main(void **state)
{
    Partie* partie= *state;
    Joueur* joueur= partie->joueurs->last->joueur;
   donner_main(partie, joueur);
   assert_int_equal(0, partie->joueurs->current->joueur->status);
   assert_int_equal(1, partie->joueurs->first->joueur->status);
}

static void test_passer_tour(void** state)
{
    Partie* partie= *state;
    setOnFirst_list_joueur(partie->joueurs);
    passer_tour(partie);
    assert_int_equal(0, partie->joueurs->current->joueur->status);
    assert_int_equal(1, partie->joueurs->first->joueur->status);
    passer_tour(partie);
    assert_int_equal(0, partie->joueurs->current->joueur->status);
    passer_tour(partie);
    assert_int_equal(0, partie->joueurs->last->joueur->status);

}

static void test_get_joueur_score_max(void** state)
{
    Partie* partie= *state;

    assert_ptr_equal(partie->joueurs->first->next->joueur,get_joueur_score_max(partie));

    partie->joueurs->first->joueur->score=0;
    partie->joueurs->first->next->joueur->score=0;
    partie->joueurs->first->next->next->joueur->score=0;
    partie->joueurs->last->joueur->score=0;

    assert_ptr_equal(partie->joueurs->current->joueur,get_joueur_score_max(partie));
}

static void test_get_score_max(void** state)
{
    Partie* partie= *state;
    Node_joueur* savecurrentnode=partie->joueurs->current;
    assert_int_equal(7,get_score_max(partie));
    assert_ptr_equal(partie->joueurs->current,savecurrentnode);
}

static void test_lancer_des(void** state)
{
    assert_in_range(lancer_des(),2,12);
    assert_in_range(lancer_des(),2,12);
    assert_in_range(lancer_des(),2,12);
    assert_in_range(lancer_des(),2,12);

}

static void test_gagne_ressource(void** state){
    Partie* partie = *state;
    partie->plateau->adjacence[0]->t->s[0].owner=partie->joueurs->first->joueur;
    partie->plateau->adjacence[0]->t->s[0].i=COLONIE;
    int proba = partie->plateau->adjacence[0]->t->proba;
    int type = partie->plateau->adjacence[0]->t->type;
    int nbCartesType = get_nbressource(type,partie->joueurs->first->joueur);
    gagne_ressource(proba,partie);
    assert_int_equal(nbCartesType+1,get_nbressource(type,partie->joueurs->first->joueur));

    partie->plateau->adjacence[0]->adjacence[0]->t->s[0].owner=partie->joueurs->first->next->joueur;
    partie->plateau->adjacence[0]->adjacence[0]->t->s[0].i=COLONIE;
    proba = partie->plateau->adjacence[0]->adjacence[0]->t->proba;
    type = partie->plateau->adjacence[0]->adjacence[0]->t->type;
    nbCartesType = get_nbressource(type,partie->joueurs->first->next->joueur);
    gagne_ressource(proba,partie);
    assert_int_equal(nbCartesType+1,get_nbressource(type,partie->joueurs->first->next->joueur));

    partie->plateau->adjacence[0]->adjacence[2]->t->s[0].owner=partie->joueurs->first->next->next->joueur;
    partie->plateau->adjacence[0]->adjacence[2]->t->s[0].i=VILLE;
    proba = partie->plateau->adjacence[0]->adjacence[2]->t->proba;
    type = partie->plateau->adjacence[0]->adjacence[2]->t->type;
    nbCartesType = get_nbressource(type,partie->joueurs->first->next->next->joueur);
    gagne_ressource(proba,partie);
    assert_int_equal(nbCartesType+2,get_nbressource(type,partie->joueurs->first->next->next->joueur));
    gagne_ressource(proba,NULL);
}

static void test_distribution_ressource(void** state){
    Partie* partie = *state;
    partie->plateau->adjacence[0]->t->s[0].owner=partie->joueurs->first->joueur;
    partie->plateau->adjacence[0]->t->s[0].i=COLONIE;
    int type1 = partie->plateau->adjacence[0]->t->type;
    int nbCartesType1 = get_nbressource(type1,partie->joueurs->first->joueur);

    partie->plateau->adjacence[0]->adjacence[0]->t->s[0].owner=partie->joueurs->first->next->joueur;
    partie->plateau->adjacence[0]->adjacence[0]->t->s[0].i=COLONIE;
    int type2 = partie->plateau->adjacence[0]->adjacence[0]->t->type;
    int nbCartesType2 = get_nbressource(type2,partie->joueurs->first->next->joueur);

    partie->plateau->adjacence[0]->adjacence[2]->t->s[0].owner=partie->joueurs->first->next->next->joueur;
    partie->plateau->adjacence[0]->adjacence[2]->t->s[0].i=COLONIE;
    int type3 = partie->plateau->adjacence[0]->adjacence[2]->t->type;
    int nbCartesType3 = get_nbressource(type3,partie->joueurs->first->next->next->joueur);

    distribution_ressource(partie);
    assert_int_equal(nbCartesType1+1,get_nbressource(type1,partie->joueurs->first->joueur));
    assert_int_equal(nbCartesType2+1,get_nbressource(type2,partie->joueurs->first->next->joueur));
    assert_int_equal(nbCartesType3+1,get_nbressource(type3,partie->joueurs->first->next->next->joueur));
    distribution_ressource(partie);

}

static void test_get_joueur_actif(void** state){
    Partie* partie = *state;
    int valtest = strcmp(partie->joueurs->current->joueur->pseudo,get_joueur_actif(partie)->pseudo);
    assert_int_equal(0,valtest);
}

static void test_nb_routes_max(void** state){
    Partie* partie = (Partie*) (*state);
    partie->joueurs->first->joueur->nbRoute = 5;
    partie->joueurs->first->next->joueur->nbRoute = 4;
    nb_routes_max(partie);
    assert_int_equal(7,partie->joueurs->first->joueur->score);
    assert_int_equal(7,partie->joueurs->first->next->joueur->score);
    partie->joueurs->first->next->joueur->nbRoute = 5;
    nb_routes_max(partie);
    assert_int_equal(6,partie->joueurs->first->joueur->score);
    assert_int_equal(7,partie->joueurs->first->next->joueur->score);
    partie->joueurs->first->next->joueur->nbRoute = 6;
    nb_routes_max(partie);
    assert_int_equal(6,partie->joueurs->first->joueur->score);
    assert_int_equal(8,partie->joueurs->first->next->joueur->score);
}

static void test_nb_routes_max_partieNULL(void** state){
    nb_routes_max(NULL);
}

static int teardown (void ** state)
{
    Partie* partie= *state;
    free (partie->joueurs);
    free(partie);
    return 0 ;
}

int main_partie_test(void)
{
    const struct CMUnitTest tests_partie[]={
        cmocka_unit_test_setup_teardown(test_get_nb_joueur,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_donner_main,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_passer_tour,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_score_max,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_score_max,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_lancer_des,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_gagne_ressource,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_distribution_ressource,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_actif,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_nb_routes_max,setup_partie,teardown),
        cmocka_unit_test(test_nb_routes_max_partieNULL)
                };
    return cmocka_run_group_tests(tests_partie,NULL,NULL);
}
