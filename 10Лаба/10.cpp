#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
	return x * x;
}

double iter_T = 0;
double iter_S = 0;

double trapec_method(double a, double b, double step, double e) {
	int i,size;
	double result = 0.0, result_prev ;
	do{
		iter_T++;
		result_prev = result;
		result = 0.0;
		size = (b - a) / step;
		double *x = new double[size];
		for (i = 0; i < size; i++)
			x[i] = a + i * step;
		for (i = 0; i < size - 1; i++) 
			result += step / 2 * (f(x[i]) + f(x[i + 1]));
		step /= 2;
		delete[]x;
		
	}while (fabs(result - result_prev) >= e);
	return result;
}

double simpson_method(double a, double b, double step, double e) {
	int i;
	double result = 0.0, result_prev;
	int size = (b - a) / step;
	if (size % 2 == 1)
		return -1;

	do {
		result_prev = result;
		result = 0.0;
		size = (b - a) / step;
		double *x = new double[size];
		for (i = 0; i < size; i++)
			x[i] = a + i * step;
		for (int i = 1; i <= size / 2; i++) {
			if (i == size / 2)
				result += step / 3 * 4 * f(x[2 * i - 1]);
			else
				result += step / 3 * (4 * f(x[2 * i - 1]) + 2 * f(x[2 * i]));
		}
		result += step / 3 * (f(x[0]) + f(x[size]));
		step /= 2;
		delete[]x;
		iter_S++;
	} while (fabs(result - result_prev) >= e);
	return result;
}

int main() {
	double a = 0.0, b = 3.0, h = 0.1;
	double e = 0.001;
	int j;
	trapec_method(a, b, h, e);
	cout << trapec_method(a, b, h, e) << " Kol-vo itercie = " << iter_T << endl;
	if (simpson_method(a, b, h, e) == -1)
		cout << "Nechetnoe kol-vo intervalo" << endl;
	else
		cout << simpson_method(a, b, h, e) << " Kol-vo itercie = " << iter_S << endl;
	return 0;
}
