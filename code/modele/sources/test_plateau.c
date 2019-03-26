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


int main_test(void){
    const struct CMUnitTest tests_plateau[] = {
        cmocka_unit_test(test_initPlateau_retourNonNul),
        cmocka_unit_test(test_freePlateau_PlateauNULL),
        cmocka_unit_test(test_freePlateau_PlateauNonNul),
    };
    return cmocka_run_group_tests(tests_plateau,group_setup,group_teardown);
}
