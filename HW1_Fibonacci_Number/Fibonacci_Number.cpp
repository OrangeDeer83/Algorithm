#include <iostream>

int recursive(int);

int iterative(int);

int explicit_formula(int);

int matrix(int);

int matrix_logarithmic(int);

int main() {
	printf("%d", iterative(5));
	
	system("PAUSE");
	return 0;
}

int recurisive(int num) {
	if (num == 1) {
		return 1;
	}
	else {
		return recurisive(1);
	}
}

int iterative(int num) {
	int sol = 1;
	if (!(num == 0 || num == 1)) {
		int n_1, n_2, i = 2;
		n_1 = n_2 = 1;
		while (i <= num) {
			n_2 = n_1;
			n_1 = sol;
			sol = n_1 + n_2;
			i++;
		}
	}
	
	return sol;
}