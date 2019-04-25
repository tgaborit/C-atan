#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "partie.h"

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
    Partie* partie= *state;
    assert_in_range(lancer_des(),2,12);
    assert_in_range(lancer_des(),2,12);
    assert_in_range(lancer_des(),2,12);
    assert_in_range(lancer_des(),2,12);

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
                };
    return cmocka_run_group_tests(tests_partie,NULL,NULL);
}
