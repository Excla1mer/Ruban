#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "graphics.h"

using namespace std;
int width = 800, height = 900;
double eps = 0.1;
double e = 2.71828182846;

double x0 = 0, x1 = 1, y_0 = 3, y_1 = 10, alpha = 0, y_ch;
//(y_1-y_0)/(x1-x0)
/*double f(double x, double y, double y_p) {
	return 6*cos(x) + 12*pow(exp,x)*y_p)-(y/pow(x+1,2));
}

*/
double f(double x, double y, double y_p) {
	return y_p*cos(x) + 6*pow(e,x)*y;
}

void init_window() {
    initwindow(width, height);
    setcolor(WHITE);
    line(width / 2, 0, width / 2, height);
    line(0, height / 2, width, height / 2);
}

void Pristrelka(double alpha) {
	double p =5;
	
	do 
	{
		y_ch = tan(alpha);
		//cout << "y_ch = " << y_ch << " alpha = " << alpha <<endl;
		if(y_ch > y_1)
		{
			alpha -= p;
			p -= 0.0001;
		}	
		else
		{
			alpha += p;
			p -= 0.0001;
		}
			
	}while(fabs(y_ch-y_1) > eps);
}

/*void runge_kutta_method_II(double *x, double *y, double *y_p, int size, double h) {
	int i;
	for (i = 1; i < size; i++) {
		y[i] = y[i - 1] + (h / 2 * f(x[i - 1], y[i - 1], y_p[i-1])) + (h / 2 * f(x[i - 1] + h, y[i - 1] + (h / 2 * f(x[i - 1], y[i - 1], y_p[i-1])), y_p[i-1]));
		y_p[i] = y_p[i-1] + f(x[i - 1], y[i - 1], y_p[i-1]);
	}
}*/

void runge_kutta_method_II(double *x, double *y, int size, double h, int n) {
	int i;
	double t = n;
	for (i = 1; i < size; i++) {
		if(i >= t)
		{
			Pristrelka(i);
			t +=n;
		}
		y[i] = y[i - 1] + (h / 2 * f(x[i - 1], y[i - 1], y_ch)) + (h / 2 * f(x[i - 1] + h, y[i - 1] + (h / 2 * f(x[i - 1], y[i - 1], y_ch)), y_ch));
		//y_p[i] = y_p[i-1] + f(x[i - 1], y[i - 1], y_p[i-1]);
	}
}

void draw_F(double *x, double *y, double size_k)
{
	setcolor(RED);
    moveto(width / 2, height / 2);
    int x_0 = getx();
    int y_0 = gety();
    for(int i = 0; i < size_k; i++)
    {
    	double coord_x = x_0 + x[i] * 90;
        double coord_y = y_0 + y[i] * 5;
        double invert_y = (coord_y - y_0) * 2;
        lineto(coord_x, coord_y - invert_y);
	}
}

int main()
{
	setlocale(0, "rus");
	Pristrelka(5);
	cout << y_ch <<endl;
	double a = 0, b = 1, h = 0.5, result = 0;
	bool f;
	int size_n = (b - a) / h + 1;
	int size_k, i, n = 1;
	double *x = new double[size_n];
	double *y = new double[size_n];
	double *y1;
	double *y_p = new double[size_n];
	y_p[0] = y_ch;
	cout << "¬ведите начальные значени€:\n ";
	x[0] = a ;
	cout << "y("<<x[0]<<") = ";
	cin >> y[0];
	runge_kutta_method_II(x, y, size_n, h, n);
	do
	{	
		f = true;
		h /= 2;
		n *= 2;
		size_k = (b - a) / h + 1;
		y1 = new double[size_k];
		y_p = new double[size_k];
		y1[0] = y[0];
		x = new double[size_k];
		for (i = 1; i < size_k; i++)
			x[i] = a + i * h;
		runge_kutta_method_II(x, y1, size_n, h, n);
		
		for(i = 0; i < size_n; i+=n)
		{
			
 			if(fabs(y[i] - y1[i*2]) > e && i!=0)
			 {
				f = false;
				break;	
			}
			
		}	
		if (f == false)
		{
			size_n = size_k;
			delete[]y;
			y = new double[size_n];
			for(i = 0; i < size_n; i++)
				y[i] = y1[i];
			delete[]y1;
			delete[]x;
			delete[]y_p;
		}
		else
		{	
			for(i = 0; i < size_k; i++)
			{
				cout << "y1[" << i << "]= " << y1[i] << " x[" << i << "] = " << x[i] << endl;
				result += h / 2 * (pow(y1[i], 2) + pow(y1[i + 1], 2));
			}
			cout << " Success!\n" << result << endl;
			init_window();
			draw_F(x, y, size_k); 
			
		}
	}
	while (f == false);
	
    system("PAUSE");
	return 1;
	
}

/*
int main()
{

	setlocale(0, "rus");
	int i,n=1;
	bool f;
	double a = 0, b = 1, h = 0.5;
	int size_n = (b - a) / h + 1;
	int size_k;
	double *x = new double[size_n];
	double *y = new double[size_n];
	double *y1;
	cout << "¬ведите начальные значени€:\n ";
	x[0] = a ;
	cout << "y("<<x[0]<<") = ";
	cin >> y[0];
	for (i = 1; i < size_n; i++)
		x[i] = a + i * h;
	cout<<endl;
	runge_kutta_method_II(x, y, size_n, h);
	delete[]x;
	cout<<"------------------------------------\n";
	do
	{	
		f = true;
		h /= 2;
		n *= 2;
		size_k = (b - a) / h + 1;
		y1 = new double[size_k];
		y1[0] = y[0];
		x = new double[size_k];
		for (i = 1; i < size_k; i++)
			x[i] = a + i * h;
		runge_kutta_method_II(x, y1, size_k, h);
		
		for(i = 0; i < size_n; i+=n)
		{
			
 			if(fabs(y[i] - y1[i*2]) > e && i!=0)
			 {
				f = false;
				break;	
			}
			
		}	
		if (f == false)
		{
			size_n = size_k;
			delete[]y;
			y = new double[size_n];
			for(i = 0; i < size_n; i++)
				y[i] = y1[i];
			delete[]y1;
			delete[]x;
		}
		else
		{	
			for(i = 0; i < size_k; i++)
			{
				cout << "y1[" << i << "]= " << y1[i] << " x[" << i << "] = " << x[i] << endl;
			}
			cout << " Success!\n";
		}
	}
	while (f == false);
    system("PAUSE");
	return 1;
}
*/


