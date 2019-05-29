#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <fstream>

const double e = 0.000001;



using namespace std;
//ofstream stm("output.txt");

double f(double x, double y) {
	//return 2 * pow(M_E, x) - x - 1;
	return cos(x);
}

void runge_kutta_method_II(double *x, double *y, int size, double h) {
	int i;
	for (i = 1; i < size; i++) {
		y[i] = y[i - 1] + (h / 2 * f(x[i - 1], y[i - 1])) + (h / 2 * f(x[i - 1] + h, y[i - 1] + (h / 2 * f(x[i - 1], y[i - 1]))));
	}
	/*for (i = 0; i < size; i++)
		cout << "y[" << i << "] = " << y[i] << endl;*/
}





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
	//for (i = 0; i < size_n; i++)
	//	cout<< x[i] << " ";
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
			//y1[i*2] =  y1[i*2] + 1 / 3 * (y1[i*2] + y[i]);
 			if(fabs(y[i] - y1[i*2]) > e && i!=0)
			 {
				//cout<<"y["<< i <<"] = "<< y[i] <<"  -  y1[" << i*2 << "] = " << y1[i*2] <<" = "<< fabs(y[i] - y1[i*2]) <<endl;
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
			/*for(i = 0; i < size_n; i+=n)
			{
			
					cout<<"y["<< i <<"] = "<< y[i] <<"  -  y1[" << i*2 << "] = " << y1[i*2] <<" = "<< fabs(y[i] - y1[i*2]) <<endl;
				//	break;
			}*/
			cout << " Success!\n";
		}
	}
	while (f == false);/*
	for(i = 0; i < size_n; i++)
	{
		cout << y[i] << " ";
	}
	cout << "\n";
	for(i = 0; i < size_k; i++)
	{
		cout << y1[i] << " ";
	}*/
	
    system("PAUSE");
	return 1;
}
