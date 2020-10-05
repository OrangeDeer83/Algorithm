#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

unsigned long long recursive(int);

unsigned long long iterative(int);

unsigned long long explicit_formula(int);

unsigned long long matrix(int);

unsigned long long matrix_logarithmic(int);

void test(int);

int main() {
	int num;
	while (true) {
		cin >> num;
		test(num);
	}
	
	system("PAUSE");
	return 0;
}

unsigned long long recursive(int num) {
	if (num == 1 || num == 0) {
		return 1;
	}
	else {
		return recursive(num - 1) + recursive(num - 2);
	}
}

unsigned long long iterative(int num) {
	unsigned long long sol = 1;
	if (!(num == 0 || num == 1)) {
		unsigned long long n_1, n_2, i = 2;
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

unsigned long long explicit_formula(int num) {
	num++;
	return (pow(((1 + sqrt(5)) / 2), num) - pow(((1 - sqrt(5)) / 2), num)) / sqrt(5);
}

unsigned long long matrix(int num) {
	if (num == 0) {
		return 1;
	}

	unsigned long long	A = 0,
						B = 1,
						C = 1,
						D = 1,
						A_temp, B_temp, C_temp, D_temp;
	while (num - 1) {
		A_temp = A;
		B_temp = B;
		C_temp = C;
		D_temp = D;
		A = B_temp;
		B = A_temp + B_temp;
		C = D_temp;
		D = C_temp + D_temp;
		num--;
	}

	return D;
}

unsigned long long matrix_logarithmic(int num) {
	if (num == 0) {
		return 1;
	}
	int times = log(num) / log(2);
	num -= pow(2, times);
	unsigned long long	A = 0,
						B = 1,
						C = 1,
						D = 1,
						BC, AaddD;
	while (times) {
		BC = B * C;
		AaddD = A + D;
		A = A * A + BC;
		B = AaddD * B;
		C = AaddD * C;
		D = D * D + BC;
		times--;
	}
	unsigned long long A_temp, B_temp ,C_temp, D_temp;
	while (num) {
		A_temp = A,
		B_temp = B,
		C_temp = C,
		D_temp = D;
		A = B_temp;
		B = A_temp + B_temp;
		C = D_temp;
		D = C_temp + D_temp;
		num--;
	}

	return D;
}

void test(int num) {
	double startTime, endTime;
	startTime = clock();
	cout << "Recursive algorithm:\t\t\t\t" << recursive(num);
	endTime = clock();
	cout << "\t" << (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	startTime = clock();
	cout << "Non-recursive definition-based algorithm:\t" << iterative(num);
	endTime = clock();
	cout << "\t" << (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	startTime = clock();
	cout << "Explicit formula algorithm:\t\t\t" << explicit_formula(num);
	endTime = clock();
	cout << "\t" << (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	startTime = clock();
	cout << "Matrix:\t\t\t\t\t\t" << matrix(num);
	endTime = clock();
	cout << "\t" << (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	startTime = clock();
	cout << "Matrix Logarithmic:\t\t\t\t" << matrix_logarithmic(num);
	endTime = clock();
	cout << "\t" << (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;
}