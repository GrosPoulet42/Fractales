#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUCurses.h>


int main(int argc, char *argv[])
{
    CU_pSuite pSuite = NULL;
    CU_initialize_registry(); // On initialise le registre
    if (CUE_SUCCESS != CU_initialize_registry()){ // On teste si l'initialisation s'est déroulee correctement
        CU_cleanup_registry(); // On libere le registre qui a ete cree
        return CU_get_error(); // Si il y a eu un problème on retourne le code d'erreur
    }
    pSuite = CU_add_suite("ma_suite", 0, 0);
    else if ((NULL == CU_add_test(pSuite, "Test assert string equal", test_fractale_get_name)) ||
             (NULL == CU_add_test(pSuite, "Test assert equal", test_fractale_get_value)) ||
             (NULL == CU_add_test(pSuite, "Test assert equal", test_fractale_get_width)) ||
             (NULL == CU_add_test(pSuite, "Test assert equal", test_fractale_get_heigth)) ||
             (NULL == CU_add_test(pSuite, "Test assert equal", test_fractale_get_a)) ||
             (NULL == CU_add_test(pSuite, "Test assert equal", test_fractale_get_b))){
        CU_cleanup_registry(); // On libere le registre qui a ete cree
        return CU_get_error(); // Si il y a eu un problème on retourne le code d'erreur
    }
    CU_basic_run_tests(); // On fait tourner les tests que nous avons cree
    CU_basic_show_failures(CU_get_failure_list()); // On affiche les erreurs
    CU_cleanup_registry(); // On libere le registre qui a ete cree
}

// Test de la fonction fractal_get_name()
void test_fractale_get_name(void){
    struct fractal * frac_test = fractal_new("fractale243", 120,640, -0.8,0.8);
    CU_ASSERT_STRING_EQUAL("fractale243",fractal_get_name(frac_test));
    fractal_free(frac_test);
}

// Test de la fonction fractal_get_value()
void test_fractale_get_value(void){
    struct fractal * frac_test = fractal_new("fractale243", 800,800, -0.8,0.8);
    fractal_set_value(frac_test, 20, 60, 350);
    CU_ASSERT_EQUAL(350,fractal_get_value(frac_test,20,60));
    fractal_free(frac_test);
}

// Test de la fonction fractal_get_width()
void test_fractale_get_width(void){
    struct fractal * frac_test = fractal_new("fractale243", 800,1200, -0.8,0.8);
    CU_ASSERT_EQUAL(800,fractal_get_width(frac_test));
    fractal_free(frac_test);
}

// Test de la fonction fractal_get_heigth()
void test_fractale_get_heigth(void){
    struct fractal * frac_test = fractal_new("fractale243", 800,1200, -0.8,0.8);
    CU_ASSERT_EQUAL(1200,fractal_get_heigth(frac_test));
    fractal_free(frac_test);
}

// Test de la fonction fractal_get_a()
void test_fractale_get_a(void){
    struct fractal * frac_test = fractal_new("fractale243", 800,1200, -0.8,0.5);
    CU_ASSERT_EQUAL(-0.8,fractal_get_a(frac_test));
    fractal_free(frac_test);
}

// Test de la fonction fractal_get_b()
void test_fractale_get_b(void){
    struct fractal * frac_test = fractal_new("fractale243", 800,1200, -0.8,0.5);
    CU_ASSERT_EQUAL(0.5,fractal_get_b(frac_test));
    fractal_free(frac_test);
}
