#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"

using namespace std;

int pow_polynom, n = 7;
double a = 0, b = 3, h = 0.1;
int width = 800, height = 900;
double X[7] = {0, 0.5, 1 , 1.5, 2, 2.5, 3};
double Y[7] = {0.01, 1, 1.02, 3, 8.3, 15.9, 26.5};

double f(double x) {
    return x*x*x;
}

void Gauss(double **array, int rows, int cols, double *&result) {
    for (int diag = 0; diag < rows - 1; diag++) {
        for (int k = diag + 1; k < rows; k++) {
            double ratio = -(array[k][diag] / array[diag][diag]);
            for (int l = 0; l < cols; l++) {
                array[k][l] += array[diag][l] * ratio;
            }
        }
    }
    result[0] = array[rows - 1][cols - 1]/array[rows - 1][cols - 2];
    double temp;
    int index_1 = 1;
    for (int m = rows - 2; m >= 0; m--) {
        int index_2 = 0;
        temp = -array[m][cols - 1];
        for (int p = cols - 2; p >= m; p--) {
            if (p == m) {
                temp /= array[m][p];
                result[index_1++] = -temp;
            }
            else {
                temp += array[m][p] * result[index_2++];
            }
        }
    }
}

double g(int number, double x) {
    if (number == 0) return 1;
    if (number == 1) return x;
    if (number == 2) return pow(x, 2);
}

double *get_coefficient(double **array) {
    double *result = (double*) malloc(pow_polynom * sizeof(double));
    double **coefficients;
    coefficients = (double**) malloc(pow_polynom * sizeof(double));
    for (int i = 0; i < pow_polynom; i++) {
        coefficients[i] = (double*) malloc((pow_polynom + 1) * sizeof(double));
    }
    for (int i = 0; i < pow_polynom; i++) {
        for (int j = 0; j <= pow_polynom; j++) {
            coefficients[i][j] = 0.0;
        }
    }
    for (int j = 0; j < pow_polynom; j++) {
        for (int p = 0; p < pow_polynom; p++) {
            for (int k = 0; k < n; k++) {
                coefficients[j][p] += g(j, array[k][0]) * g(p, array[k][0]);
            }
        }
    }
    for (int p = 0; p < pow_polynom; p++) {
        for (int i = 0; i < n; i++) {
            coefficients[p][pow_polynom] += array[i][1] * g(p, array[i][0]);
        }
    }
    Gauss(coefficients, pow_polynom, pow_polynom + 1, result);
    return result;
}

double approx_function(double *coef, double x) {
    double value = 0;
    for (int i = 0, k = pow_polynom - 1; i < pow_polynom; i++, k--) {
        value += coef[i] * g(k, x);
    }
    return value;
}

void init_window() {
    initwindow(width, height);
    setcolor(WHITE);
    line(width / 2, 0, width / 2, height);
    line(0, height / 2, width, height / 2);
}

void draw_function(int begin, int end) {
    moveto(width / 2, height / 2);
    setcolor(WHITE);
   
    int x_0 = getx();
    int y_0 = gety();
    int hz = 0;
    for (int i = 0; i < 8; i++) {
    	
        double x = X[hz];
		double y = Y[hz];
        double coord_x = x_0 + x * 80;
        double coord_y = y_0 + y * 10;
        double invert_y = (coord_y - y_0) * 2;
        setfillstyle(1, WHITE);
            circle(coord_x, coord_y - invert_y, 5);
           // floodfill(coord_x, coord_y - invert_y, WHITE);
            setcolor(WHITE);
        //if (x == begin) moveto(coord_x, coord_y - invert_y);
        //lineto(coord_x, coord_y - invert_y);
		hz++;
    }
}
/*void draw_function(int begin, int end) {
    moveto(width / 2, height / 2);
    setcolor(MAGENTA);
    int x_0 = getx();
    int y_0 = gety();
    double y;
    for(int i = 0; i < 5; i++){
	y = f(X[i]);
    for (double x = begin; x <= end; x += 0.01) {
		
        double coord_x = x_0 + x * 30;
        double coord_y = y_0 + y * 30;
        double invert_y = (coord_y - y_0) * 2;
        if (x == begin) moveto(coord_x, coord_y - invert_y);
        lineto(coord_x, coord_y - invert_y);
    }
    }
}*/

void draw_polynom(int begin, int end, double *coefficient, double **array_values) {
    double round_x, round_el_array;
    int i = 0;
    setcolor(GREEN);
    moveto(width / 2, height / 2);
    int x_0 = getx();
    int y_0 = gety();
    for(double x = begin; x <= end; x += 1) 
	{
        double y = approx_function(coefficient, x);
        double coord_x = x_0 + x * 80;
        double coord_y = y_0 + y * 10;
        double invert_y = (coord_y - y_0) * 2;
        round_x = round(x * 1000000) / 1000000;
        round_el_array = round(array_values[i][0] * 10000000) / 10000000;
       /** if (round_x == round_el_array) {
           // setcolor(RED);
            setfillstyle(1, RED);
            circle(coord_x, coord_y - invert_y, 7);
            floodfill(coord_x, coord_y - invert_y, RED);
            setcolor(YELLOW);
            i++;
            if (i == n) i = 0;
        }*/
        if (x == begin) moveto(coord_x, coord_y - invert_y);
        lineto(coord_x, coord_y - invert_y);
    }
}
void draw_F()
{
	setcolor(RED);
    moveto(width / 2, height / 2);
    int x_0 = getx();
    int y_0 = gety();
    for(double i = 0; i < 4; i+=h)
    {
    	double coord_x = x_0 + i * 80;
        double coord_y = y_0 + f(i) * 10;
        double invert_y = (coord_y - y_0) * 2;
        lineto(coord_x, coord_y - invert_y);
    	cout << "i = " << i << "f(i) = " << f(i) << endl;
	}
}
int main() {
	
	double count = 0;
	int i = 0, N = 7;
    pow_polynom = 3;
   /* printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("h = ");
    scanf("%lf", &h);
   // n=5;
    

/*	count = a;
	while (count <= b) {
		count += h;
		i++;
	}

	N = i;
    n = N;*/
    
    double *res = (double*) malloc(pow_polynom * sizeof(double));
    double **array_x_y;
    array_x_y = (double**) malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        array_x_y[i] = (double*) malloc(N * sizeof(double));
    }
    for (int i = 0; i < N; i++) {
       // array_x_y[i][0] = a + i * h;
      //  array_x_y[i][1] = f(array_x_y[i][0]);
      	array_x_y[i][0] = X[i];
      	array_x_y[i][1] = Y[i];
    }
    res = get_coefficient(array_x_y);
    for (int i = 0; i < pow_polynom; i++) printf("%lf ", res[i]);
    init_window();
    draw_function(a, b);
    draw_F();
    draw_polynom(a, b, res, array_x_y);
    system("pause");
}
