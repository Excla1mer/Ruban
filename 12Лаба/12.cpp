#include <iostream>
#include "graphics.h"
#include <conio.h>
#include <math.h>
using namespace std;

double Left=10;
double Top=10;
double Width=800;
double Height=600;
double x_min=-1;
double x_max=7;
double y_min=-3;
double y_max=2;

double Xs(double x)
{
	return (Left+(Width/(x_max-x_min))*(x-x_min));
}

double Ys(double y)
{
	return (Top+Height-(Height/(y_max-y_min))*(y-y_min));
}




int main()
{ 
	initwindow(800,600);
	
	
}
