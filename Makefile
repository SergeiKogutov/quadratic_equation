check:
	gcc -Werror -Wall -Wextra -std=c11 -lcheck quadratic_equation.c test_quadratic_equation.c -o test_quadratic_equation
	./test_quadratic_equation

rebuild: clean check

clean: 
	rm -rf test_quadratic_equation

clang:
	clang-format -n *.c *.h  --verbose
	clang-format -i *.c *.h  --verbose