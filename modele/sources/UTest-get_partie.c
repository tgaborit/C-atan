#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <cmocka_pbc.h>
#include <string.h>
#include "get_plateau.h"
#include "get_partie.h"
#include "set_partie.h"
#include "UTest-get_partie.h"
#include "partie.h"


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

    get_joueur_actif(partie)->carte_dev[MONOPOLE].nb_carte=0;
    get_joueur_actif(partie)->carte_dev[CHEVALIER].nb_carte=1;
    get_joueur_actif(partie)->carte_dev[ROUTES].nb_carte=2;
    get_joueur_actif(partie)->carte_dev[POINT].nb_carte=3;
    get_joueur_actif(partie)->carte_dev[DECOUVERTE].nb_carte=4;

    get_joueur_actif(partie)->ressource[BLE].nb_ressource=0;
    get_joueur_actif(partie)->ressource[BOIS].nb_ressource=1;
    get_joueur_actif(partie)->ressource[PIERRE].nb_ressource=2;
    get_joueur_actif(partie)->ressource[ARGILE].nb_ressource=3;
    get_joueur_actif(partie)->ressource[MOUTON].nb_ressource=4;


    *state = partie;
    return 0;
}

static void test_get_nb_joueur(void **state)
{
    Partie* partie= *state;
    int c= get_nbjoueurs(partie);
    assert_int_equal(4, c);
}

static void test_get_nbcartedev_joueuractif(void** state){
    Partie* partie= *state;
    int i;
    for(i=0;i<=4;++i){
        assert_int_equal(i,get_nbcartedev_joueuractif(i,partie));
    }
}

static void test_get_nbressource_joueuractif(void** state){
    Partie* partie= *state;
    int i;
    for(i=0;i<=4;++i){
        assert_int_equal(i,get_nbressource_joueuractif(i,partie));
    }
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

static int teardown (void ** state)
{
    Partie* partie= *state;
    free (partie->joueurs);
    free(partie);
    return 0 ;
}

int main_get_partie_test(void)
{
    const struct CMUnitTest tests_get_partie[]={
        cmocka_unit_test_setup_teardown(test_get_nbcartedev_joueuractif,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_nbressource_joueuractif,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_nb_joueur,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_score_max,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_score_max,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_actif,setup_partie,teardown),
        cmocka_unit_test_setup_teardown(test_get_joueur_actif,setup_partie,teardown),

        };
    return cmocka_run_group_tests(tests_get_partie,NULL,NULL);
}
