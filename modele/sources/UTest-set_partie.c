#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <cmocka_pbc.h>
#include <string.h>
#include "get_plateau.h"
#include "UTest-set_partie.h"
#include "partie.h"
#include "get_partie.h"
#include "set_partie.h"

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
    Joueur* joueur_3=init_joueur(BLANC,"joueur3");
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

static int setup_partie_ressource (void ** state)
{
        Partie* partie= init_partie();
    if(partie==NULL)
        {
        printf("erreur init partie\n");
        return -1;
        }


    Joueur* joueur_1=init_joueur(ROUGE,"joueur1");
    Joueur* joueur_2=init_joueur(BLEU,"joueur2");
    Joueur* joueur_3=init_joueur(BLANC,"joueur3");
    Joueur* joueur_4=init_joueur(ORANGE,"joueur4");

    if (joueur_1==NULL || joueur_2==NULL || joueur_3==NULL || joueur_4==NULL )
        {
        printf("erreur init joueur\n");
        return -1;
        }
    joueur_1->ressource[BLE].nb_ressource=0;
    joueur_1->ressource[BOIS].nb_ressource=1;
    joueur_1->ressource[PIERRE].nb_ressource=2;
    joueur_1->ressource[ARGILE].nb_ressource=3;
    joueur_1->ressource[MOUTON].nb_ressource=4;

    joueur_2->ressource[BLE].nb_ressource=0;
    joueur_2->ressource[BOIS].nb_ressource=1;
    joueur_2->ressource[PIERRE].nb_ressource=2;
    joueur_2->ressource[ARGILE].nb_ressource=3;
    joueur_2->ressource[MOUTON].nb_ressource=4;

    joueur_3->ressource[BLE].nb_ressource=0;
    joueur_3->ressource[BOIS].nb_ressource=1;
    joueur_3->ressource[PIERRE].nb_ressource=2;
    joueur_3->ressource[ARGILE].nb_ressource=3;
    joueur_3->ressource[MOUTON].nb_ressource=4;

    joueur_4->ressource[BLE].nb_ressource=0;
    joueur_4->ressource[BOIS].nb_ressource=1;
    joueur_4->ressource[PIERRE].nb_ressource=2;
    joueur_4->ressource[ARGILE].nb_ressource=3;
    joueur_4->ressource[MOUTON].nb_ressource=4;

    add_joueur(joueur_1,partie);
    add_joueur(joueur_2,partie);
    add_joueur(joueur_3,partie);
    add_joueur(joueur_4,partie);

    *state = partie;
    return 0;
}

static void test_findjoueur(void** state)
{
    Partie* partie= *state;
    Joueur* joueur_1 =partie->joueurs->current->next->joueur;
    Joueur* joueur_test= init_joueur(ORANGE,"toto");
    assert_int_equal(0,find_joueur(partie,joueur_1));
    assert_ptr_equal(joueur_1,partie->joueurs->current->joueur);

    assert_int_equal(-1,find_joueur(partie,joueur_test));
    assert_ptr_equal(joueur_1,partie->joueurs->current->joueur);
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
   find_joueur(partie, joueur);
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

static void test_get_joueur_actif(void** state){
    Partie* partie = *state;
    int valtest = strcmp(partie->joueurs->current->joueur->pseudo,get_joueur_actif(partie)->pseudo);
    assert_int_equal(0,valtest);
}

static void test_lancer_des(void** state)
{

    Partie* partie = (Partie*) *(state);
    int lancer = lancer_des(partie);
    assert_in_range(lancer,2,12);
    assert_int_equal(lancer,get_des(partie));

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

static void test_obtenir_cartedev(void** state)
{
    Partie* partie= *state;
    int flag,n=0,i;
    Joueur* joueur= partie->joueurs->current->joueur;
    gain_ressource(MOUTON,joueur);
    gain_ressource(BLE,joueur);
    gain_ressource(PIERRE,joueur);
    flag=obtenir_cartedev(partie);

    for(i=0;i<=4;++i){
        n+=joueur->carte_dev[i].nb_carte;
    }
    assert_int_equal(0,flag);
    assert_int_equal(1,n);

    flag=obtenir_cartedev(partie);
    n=0;
    for(i=0;i<=4;++i){
        n+=joueur->carte_dev[i].nb_carte;
    }
    assert_int_equal(-1,flag);
    assert_int_equal(1,n);
}

static void test_utiliser_monopole(void** state){
    Partie* partie= *state;
    int flag;
    int nb;
    partie->joueurs->current->joueur->carte_dev[MONOPOLE].nb_carte=4;

    flag=utiliser_monopole(partie,BLE);
    nb=get_nbressource(BLE,partie->joueurs->current->joueur);
    assert_int_equal(0,flag);
    assert_int_equal(0,nb);


    flag=utiliser_monopole(partie,BOIS);
    nb=get_nbressource(BOIS,partie->joueurs->current->joueur);
    assert_int_equal(4,flag);
    assert_int_equal(4,nb);

    flag=utiliser_monopole(partie,PIERRE);
    nb=get_nbressource(PIERRE,partie->joueurs->current->joueur);
    assert_int_equal(8,flag);
    assert_int_equal(8,nb);


    flag=utiliser_monopole(partie,ARGILE);
    nb=get_nbressource(ARGILE,partie->joueurs->current->joueur);
    assert_int_equal(12,flag);
    assert_int_equal(12,nb);

    flag=utiliser_monopole(partie,MOUTON);
    nb=get_nbressource(MOUTON,partie->joueurs->current->joueur);
    assert_int_equal(-1,flag);
    assert_int_equal(4,nb);

}

static void test_utiliser_decouverte(void** state){
    Partie* partie= *state;
    int flag;
    int nb1,nb2;
    get_joueur_actif(partie)->carte_dev[DECOUVERTE].nb_carte=2;
    flag=utiliser_decouverte(partie,BLE,BLE);
    nb1=get_nbressource(BLE,get_joueur_actif(partie));
    assert_int_equal(0,flag);
    assert_int_equal(2,nb1);

    flag=utiliser_decouverte(partie,BOIS,BLE);
    nb1=get_nbressource(BOIS,get_joueur_actif(partie));
    nb2=get_nbressource(BLE,get_joueur_actif(partie));
    assert_int_equal(0,flag);
    assert_int_equal(2,nb1);
    assert_int_equal(3,nb2);

    flag=utiliser_decouverte(partie,PIERRE,BOIS);
    nb1=get_nbressource(PIERRE,get_joueur_actif(partie));
    nb2=get_nbressource(BOIS,get_joueur_actif(partie));
    assert_int_equal(-1,flag);
    assert_int_equal(2,nb1);
    assert_int_equal(2,nb2);
}

static void test_utiliser_point(void** state){
    Partie* partie= *state;
    int flag;
    int nb;
    get_joueur_actif(partie)->carte_dev[POINT].nb_carte=2;

    flag=utiliser_point(partie);
    nb=get_score(get_joueur_actif(partie));
    assert_int_equal(0,flag);
    assert_int_equal(1,nb);

    flag=utiliser_point(partie);
    nb=get_score(get_joueur_actif(partie));
    assert_int_equal(0,flag);
    assert_int_equal(2,nb);

    flag=utiliser_point(partie);
    nb=get_score(get_joueur_actif(partie));
    assert_int_equal(-1,flag);
    assert_int_equal(2,nb);

}

static void test_utiliser_routes_sanscarte(void** state)
{
    Partie* partie= *state;
    int flag= utiliser_routes(partie,1,0,2,0,1,1);
    assert_int_equal(flag,-1);
}
static void test_utiliser_routes_mauvaises_coordonnees(void** state)
{
    Partie* partie= *state;
    int flag= utiliser_routes(partie,1,0,2,0,1,1);
    assert_int_equal(flag,-1);
}

static void test_utiliser_routes_1bonne_coordonnee(void** state)
{
    Partie* partie= *state;
    Plateau* plateau= partie->plateau;
    partie->joueurs->current->joueur->carte_dev[ROUTES].nb_carte=1;

    Noeud* cur = deplacementPlateau(plateau,1,0);
    cur->t->s[0].i=COLONIE;
    cur->t->s[0].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0.5,1);
    cur->t->s[4].i=COLONIE;
    cur->t->s[4].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0,0);
    cur->t->s[2].i=COLONIE;
    cur->t->s[2].owner=get_joueur_actif(partie);

    int flag= utiliser_routes(partie,1,0,2,0,1,1);
    assert_int_equal(flag,-1);
    assert_ptr_equal(getJoueurArrete(partie,1,0,1),NULL);
    assert_int_equal(1,get_nbcartedev_joueuractif(ROUTES,partie));
}

static void test_utiliser_routes_bonnes_coordonnees(void** state)
{
    Partie* partie= *state;
    Plateau* plateau= partie->plateau;
    partie->joueurs->current->joueur->carte_dev[ROUTES].nb_carte=1;

    Noeud* cur = deplacementPlateau(plateau,1,0);
    cur->t->s[0].i=COLONIE;
    cur->t->s[0].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0.5,1);
    cur->t->s[4].i=COLONIE;
    cur->t->s[4].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0,0);
    cur->t->s[2].i=COLONIE;
    cur->t->s[2].owner=get_joueur_actif(partie);

    cur=deplacementPlateau(plateau,2,0);
    cur->t->s[0].i=COLONIE;
    cur->t->s[0].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,1.5,1);
    cur->t->s[4].i=COLONIE;
    cur->t->s[4].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,1,0);
    cur->t->s[2].i=COLONIE;
    cur->t->s[2].owner=get_joueur_actif(partie);

    int flag= utiliser_routes(partie,1,0,2,0,1,1);
    assert_int_equal(flag,0);
    assert_ptr_equal(getJoueurArrete(partie,1,0,1),get_joueur_actif(partie));
    assert_ptr_equal(getJoueurArrete(partie,2,0,1),get_joueur_actif(partie));
    assert_int_equal(0,get_nbcartedev_joueuractif(ROUTES,partie));
}
static void test_utiliser_chevalier(void** state)
{
    Partie* partie= *state;
    Plateau* plateau= partie->plateau;
    Joueur* joueur_vole= get_joueur_actif(partie);
    Noeud* cur = deplacementPlateau(plateau,1,0);
    cur->t->s[0].i=COLONIE;
    cur->t->s[0].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0.5,1);
    cur->t->s[4].i=COLONIE;
    cur->t->s[4].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0,0);
    cur->t->s[2].i=COLONIE;
    cur->t->s[2].owner=get_joueur_actif(partie);

    setOnNext_list_joueur(partie->joueurs);
    partie->joueurs->current->joueur->carte_dev[CHEVALIER].nb_carte=1;
    int flag= utiliser_chevalier(partie,1,0,joueur_vole);
    assert_int_equal(0,flag);
    assert_int_equal(get_nbressource_total(joueur_vole),9);
    assert_int_equal(get_nbressource_total(get_joueur_actif(partie)),11);

}

static void test_utiliser_chevalier_sansjoueur(void** state){
    Partie* partie= *state;
    Joueur* joueur_vole= get_joueur_actif(partie);
    setOnNext_list_joueur(partie->joueurs);
    partie->joueurs->current->joueur->carte_dev[CHEVALIER].nb_carte=1;
    int flag= utiliser_chevalier(partie,1,0,joueur_vole);
    assert_int_equal(-1,flag);
    assert_int_equal(get_nbressource_total(joueur_vole),10);
    assert_int_equal(get_nbressource_total(get_joueur_actif(partie)),10);
}

static void test_utiliser_chevalier_sanscarte(void** state){
    Partie* partie= *state;
    Plateau* plateau= partie->plateau;
    Joueur* joueur_vole= get_joueur_actif(partie);
    Noeud* cur = deplacementPlateau(plateau,1,0);
    cur->t->s[0].i=COLONIE;
    cur->t->s[0].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0.5,1);
    cur->t->s[4].i=COLONIE;
    cur->t->s[4].owner=get_joueur_actif(partie);
    cur=deplacementPlateau(plateau,0,0);
    cur->t->s[2].i=COLONIE;
    cur->t->s[2].owner=get_joueur_actif(partie);

    setOnNext_list_joueur(partie->joueurs);
    partie->joueurs->current->joueur->carte_dev[CHEVALIER].nb_carte=0;
    int flag= utiliser_chevalier(partie,1,0,joueur_vole);
    assert_int_equal(-1,flag);
    assert_int_equal(get_nbressource_total(joueur_vole),10);
    assert_int_equal(get_nbressource_total(get_joueur_actif(partie)),10);

}

static void test_action_voleur(void** state){
    Partie* partie= *state;
    int i;
    action_voleur(partie);
    for(i=1;i<=4;++i){
    assert_int_equal(5, get_nbressource_total(get_joueur_actif(partie)));
    setOnNext_list_joueur(partie->joueurs);
    }
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
        cmocka_unit_test_setup_teardown(test_findjoueur,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_donner_main,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_passer_tour,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_score_max,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_score_max,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_actif,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_nb_routes_max,setup_partie,teardown),
        cmocka_unit_test(test_nb_routes_max_partieNULL),
        cmocka_unit_test_setup_teardown(test_lancer_des,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_gagne_ressource,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_distribution_ressource,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_actif,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_obtenir_cartedev,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_monopole,setup_partie_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_decouverte,setup_partie_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_point,setup_partie_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_routes_sanscarte,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_routes_bonnes_coordonnees,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_routes_mauvaises_coordonnees,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_routes_1bonne_coordonnee,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_chevalier,setup_partie_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_chevalier_sansjoueur,setup_partie_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_utiliser_chevalier_sanscarte,setup_partie_ressource,teardown),
        cmocka_unit_test_setup_teardown(test_action_voleur,setup_partie_ressource,teardown),
        };
    return cmocka_run_group_tests(tests_partie,NULL,NULL);
}
