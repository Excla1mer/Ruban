#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>

const double e = 0.1;
//double const step = 0.1;
using namespace std;
ofstream stm("output.txt");

double f(double x, double y) {
	//return 2 * pow(M_E, x) - x - 1;
	return x * x;
}

void runge_kutta_method_II(double *x, double *y, int size, double h) {
	int i;
	for (i = 1; i < size; i++) {
		y[i] = y[i - 1] + h / 2 * f(x[i - 1], y[i - 1] + h / 2 * f(x[i - 1], y[i - 1]));
	}
	for (i = 0; i < size; i++)
		cout << "x[" << i << "] = " << x[i] << "\ty[" << i << "] = " << y[i] << endl;
}

/*double* DoubleRecalculation(double start, double end, const double Y[2], double step, bool output, double *&values, double printStep)//метод двойного пересчёта
{

    stm << "\r\nDOUBLE RECALCULATION: STEP = " << step << endl;
	double *Y1, *Y2;
	int size = (end - start / step)+1;
	//cout<<"SIZE:"<<size<<endl;
	int devider =  size * printStep;
	//cout<<"DIVIDER"<<devider<<endl;
	int i = 1, k = 0;
	values = new double[(int)((end-start)/printStep)+1];
	values[k] = Y[0];
	k++;
	Y1 = new double[2];
	Y2 = new double[2];
	Y1[0] = Y[0];
	Y1[1] = Y[1];

	Y2[0] = Y[0];
	Y2[1] = Y[1];

	double x = start;
	do
	{

		Y1 = Runge_Kutta_4th(x,Y1,step);
		Y2 = Runge_Kutta_4th(x,Y2,step/2);
		Y2 = Runge_Kutta_4th(x+step/2,Y2, step/2);

		if(devider != 0 && i % devider == 0)//запись в массив для последующего вывода в консоль
			values[k++] = Y2[0];

		if(output)
		{
			stm << "X" << x+step <<"\t\tY(функция): " << Y2[0] <<  "\t\tY'(производная): " << Y2[1] << endl;
			putpixel((int)(x*lengthS) + xS,yS-(int)(Y2[0]*lengthS/3),14);//график функции
			putpixel((int)(x*lengthS) + xS,yS-(int)(Y2[1]*lengthS/3)+10,13);//производной
		}

		if(fabs(Y1[0] - Y2[0]) > 15*epsilon || fabs(Y1[1] - Y2[1]) > 15*epsilon)
		{

			step /= 2;
			if(output)
                stm << "\r\nNEW STEP: " << step << endl;
			x = start;

			Y1[0] = Y[0];
			Y1[1] = Y[1];

			Y2[0] = Y[0];
			Y2[1] = Y[1];
			i = 1;
			k = 0;
			size = (end - start) / step;
			devider = size * printStep+1;
			values[k++] = Y[0];
			//system("PAUSE");
		}
		else
			x += step;

		i++;
	}
	while(x < end);

	values[k++] = Y2[0];
	return Y2;
}
*/


int main()
{
	setlocale(0, "rus");
	int i,n=1;
	bool f;
	double a = 1, b = 2, h = 0.1;
	int size = (b - a) / h + 1;
	double *x = new double[size];
	double *y = new double[size];
	cout << "Введите начальные значения:\nx[0] = ";
	cin >> x[0];
	cout << "y("<<x[0]<<") = ";
	cin >> y[0];
	for (i = 1; i < size; i++)
		x[i] = a + i * h;
	runge_kutta_method_II(x, y, size, h);
	do
	{	
		f = true;
		double *y1 = new double[size];
		for(i = 0; i < size; i++)
			y1[i] = y[i];
		h /= 2;
		n *= 2;
		size = (b - a) / h + 1;
		y = new double[size];
		runge_kutta_method_II(x, y, size, h);
		
		for(i = 0; i < size; i+=n)
		{
			if(fabs(y[i] - y1[i/n]) > e && i!=0)
			{
				cout<< y[i] <<"  |  "<<y1[i]<<" = "<< fabs(y[i] - y1[i/n])<<endl;
				f = false;
				delete[]y;
				delete[]y1;
			}
		}	
	}
	while (f== false);
	for(i = 0; i < size; i++)
	{
		cout << y[i] << " ";
	}
	h *= 2;
	size = (b - a) / h + 1;
	cout << "\n";
	for(i = 0; i < size; i++)
	{
		//cout << y1[i] << " ";
	}
	delete[]x;
	
    system("PAUSE");
	return 1;
}
