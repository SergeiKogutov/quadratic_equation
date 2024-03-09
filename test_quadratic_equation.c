#include "test_quadratic_equation.h"

START_TEST(quadratic_equation_0) {
  double *res = solve_equation(1, 2, -3);
  double x1 = res[0];
  double x2 = res[1];
  printf("\ntest 1: x^2 + 2x - 3 = 0 \nx1 = %f, x2 = %f\n\n", x1, x2);
  ck_assert_double_eq(-3, x1);
  ck_assert_double_eq(1, x2);
}
END_TEST

START_TEST(quadratic_equation_1) {
  double *res = solve_equation(2, 4, -1);
  double x1 = res[0];
  double x2 = res[1];
  printf("test 2: 2x^2 + 4x - 1 = 0 \nx1 = %f, x2 = %f\n\n", x1, x2);
  ck_assert_double_eq_tol(-2.2247, x1, 1e-4);
  ck_assert_double_eq_tol(0.2247, x2, 1e-4);
}
END_TEST

START_TEST(quadratic_equation_2) {
  double *res = solve_equation(-2, 7, -2);
  double x1 = res[0];
  double x2 = res[1];
  printf("test 3: - 2x^2 + 7x - 2 = 0 \nx1 = %f, x2 = %f\n\n", x1, x2);
  ck_assert_double_eq_tol(3.1861, x1, 1e-4);
  ck_assert_double_eq_tol(0.3138, x2, 1e-4);
}
END_TEST

Suite *test_solve_equation(void) {
  Suite *s = suite_create("\033[1;3;5;42;31m-=olve_equation=-\033[0m");
  TCase *tc = tcase_create("quadratic_equation_tc");
  tcase_add_test(tc, quadratic_equation_0);
  tcase_add_test(tc, quadratic_equation_1);
  tcase_add_test(tc, quadratic_equation_2);
  suite_add_tcase(s, tc);

  return s;
}

void run() {
  Suite *tests[] = {
      test_solve_equation(),
      NULL,
  };

  int total = 0, failed = 0;

  for (Suite **current = tests; *current; current++) {
    SRunner *sr = srunner_create(*current);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    total += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }
  printf("\n"
         " total: %d "
         " failed: %d "
         " success: %d "
         "\n",
         total, failed, total - failed);
}

int main() {
  run();
  return 0;
}
