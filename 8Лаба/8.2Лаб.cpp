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
double F(double x)
{
	return cos(x);
}

//double T=2;
int n=4;
double x[4]={0,1.57,3.14,4.712};
double y[4]={1,0,-1,0};
double h[4];
double C[10][10];
double M[4];
double d[4];
double S;
double S1;
double S2;
double S3;
double S4;
bool f=true;

double Gays(int n);

int main()
{
	initwindow(800,600);
	int i,r,j;
	setcolor(15);
	circle(Xs(x[0]),Ys(y[0]),10);
	circle(Xs(x[1]),Ys(y[1]),10);
	circle(Xs(x[2]),Ys(y[2]),10);
	circle(Xs(x[3]),Ys(y[3]),10);
	//circle(Xs(x[4]),Ys(y[4]),10);
	setcolor(2);
	moveto(Xs(x[0]),Ys(y[0]));
	for(double w=0;w<=6.3;w+=0.1)
	{
		lineto(Xs(w),Ys(F(w)));
	}
	setcolor(12);
	moveto(Xs(x[0]),Ys(y[0]));
	for(double T=0;T<=6.3;T+=0.1)
	{
		for(i=0;i<n-1;i++)
		{
			if(x[i]<=T&&x[i+1]>T)
			{
				r=i+1;
			}	
		}
		for(i=1;i<n;i++)
		{
			h[i]=x[i]-x[i-1];
		}
		//Zapolnenie Matrichi C[i][j]
		for(i=1;i<n-1;i++)
		{
			d[i]=((y[i+1]-y[i])/h[i+1])-((y[i]-y[i-1])/h[i]);
			for(j=1;j<n-1;j++)
			{
				if(i==j)
				{
					C[i][j]=(h[i]+h[i+1])/3;
				}
				else{
					if(j==i+1)
					{
						C[i][j]=(h[i+1])/6;
					}
					else{
						if(j==i-1){
							C[i][j]=h[i]/6;
						}
						else{
							C[i][j]=0;
						}
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<h[i]<<"\t";
		}
		cout<<endl;
		for(i=0;i<n;i++)
		{
			cout<<d[i]<<"|"<<y[i]<<"|"<<"\t";
		}
		cout<<endl;
		Gays(2);
		for(i=0;i<n;i++)
		{
			cout<<M[i]<<"\t";
		}
		S1=(M[r-1]*pow((x[r]-T),3))/(6*h[r]);
		S2=(M[r]*pow((T-x[r-1]),3)/(6*h[r]));
		S3=(y[r-1]-((M[r-1]*h[r]*h[r])/6))*((x[r]-T)/h[r]);
		S4=(y[r]-((M[r]*h[r]*h[r])/6))*((T-x[r-1])/h[r]);
		S=S1+S2+S3+S4;
		lineto(Xs(T),Ys(S));
	}
	cout<<"\n"<<cos(1.57)<<endl;
	getch();
	closegraph();
	
}

double Gays(int n)
{
	int i,j,rememb_str,rememb_elem;
	bool f=true,b=false;
	double a[10][10],Mat_x[100];
	double t,max;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=C[i+1][j+1];
		}
		a[i][n]=d[i+1];
	}	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%f\t",a[i][j]);
		}
		cout<<"\n";
	}
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
			if(i==j&&a[i][j]==0)
			{
				max=a[i][j];
				for(int z=i+1;z<n;z++)
				{
					if(max<a[z][j])
					{
						max=a[z][j];
						rememb_str=z;
					}
				}
				for(int z=0;z<n+1;z++)
				{
					rememb_elem=a[i][z];
					a[i][z]=a[rememb_str][z];
					a[rememb_str][z]=rememb_elem;
				}
			}
				if(j-i<0)
				{
					t=a[i][j]/a[j][j];
					for(int z=j;z<n+1;z++)
					{
						a[i][z]=a[i][z]-(a[j][z]*t);
					}
				}	
		}
	}
	cout<<endl;
	for(i=n-1;i>=0;i--)
	{
		Mat_x[i]=a[i][n]/a[i][i];
		
		for(j=n-1;j>i;j--)
		{
			
			Mat_x[i]=Mat_x[i]-a[i][j]*Mat_x[j]/a[i][i];
			
			
		}
		
	}
	M[n]=Mat_x[n-1];
	M[n-1]=Mat_x[n-2];
}
