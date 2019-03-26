#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include "cmocka_pbc.h"
#include "plateau.h"
#include "test_plateau.h"

static int group_setup(void** state){
    Plateau* p = initPlateau();
    if(p != NULL){
        (*state) = p;
        return 0;
    }
    return -1;
}

static int group_teardown(void** state){
    freePlateau((*state));
    return 0;
}

static void test_initPlateau_retourNonNul(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_ptr_not_equal(p,NULL);
}

static void test_freePlateau_PlateauNonNul(void** state){
    Plateau* p = initPlateau();
    assert_int_equal(0,freePlateau(p));
}

static void test_freePlateau_PlateauNULL(void** state){
    assert_int_equal(-1,freePlateau(NULL));
}

static void test_deplacementPlateau_coordBonnes(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_int_equal((int) p,(int)deplacementPlateau(p,0,0));
    assert_int_equal((int)p->adjacence[4]->adjacence[4],(int)deplacementPlateau(p,1,2));
    assert_int_equal((int)p->adjacence[1],(int)deplacementPlateau(p,-0.5,-1));
    assert_int_equal((int)p->adjacence[2]->adjacence[4],(int)deplacementPlateau(p,0,2));
    assert_int_equal((int)p->adjacence[3]->adjacence[1],(int)deplacementPlateau(p,0,-2));
    assert_int_equal((int)p->adjacence[0]->adjacence[0],(int)deplacementPlateau(p,-2,0));
    assert_int_equal((int)p->adjacence[5]->adjacence[5],(int)deplacementPlateau(p,2,0));
}

static void test_deplacementPlateau_coordFausses(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_ptr_equal(NULL,deplacementPlateau(p,-2,-2));
    assert_ptr_equal(NULL,deplacementPlateau(p,-0.5,-2));
    assert_ptr_equal(NULL,deplacementPlateau(p,0,0.5));
}

static void test_deplacementPlateau_PlateauNull(void** state){
    assert_ptr_equal(NULL,deplacementPlateau(NULL,2,0));
}

static void test_bougerVoleur_coordBonnes(void** state){
    Plateau* p = (Plateau*) (*state);
    bougerVoleur(p,1.5,1);
    assert_int_equal(p->t->brigand,0);
    assert_int_equal(deplacementPlateau(p,1.5,1)->t->brigand,1);
}

static void test_bougerVoleur_PlateauNULL(void** state){
    assert_int_equal(bougerVoleur(NULL,2,0),-1);
}

static void test_bougerVoleur_coordFausses(void** state){
    Plateau* p = (Plateau*) (*state);
    assert_int_equal(bougerVoleur(p,10,10),-1);
}

int main_test(void){
    const struct CMUnitTest tests_plateau[] = {
        cmocka_unit_test(test_initPlateau_retourNonNul),
        cmocka_unit_test(test_freePlateau_PlateauNULL),
        cmocka_unit_test(test_freePlateau_PlateauNonNul),
	cmocka_unit_test(test_deplacementPlateau_coordBonnes),
        cmocka_unit_test(test_deplacementPlateau_coordFausses),
        cmocka_unit_test(test_deplacementPlateau_PlateauNull),
	cmocka_unit_test(test_bougerVoleur_coordBonnes),
        cmocka_unit_test(test_bougerVoleur_coordFausses),
        cmocka_unit_test(test_bougerVoleur_PlateauNULL)
    };
    return cmocka_run_group_tests(tests_plateau,group_setup,group_teardown);
}
