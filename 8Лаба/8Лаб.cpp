#include <iostream>
#include <math.h>
using namespace std;


double T=2;
int n=4;
double x[4]={1,3,7,9};
double y[4]={2,6,-2,6};
double h[4];
double C[10][10];
double M[4];
double d[4];
double S;
bool f=true;

double Gays(int n);

int main()
{
	int i,r,j;
	for(i=0;i<n-1;i++)
	{
		if(x[i]<T&&x[i+1]>T)
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
	cout<<endl;

	S=(M[r-1]*pow((x[r]-T),3))/(6*h[r])+(M[r]*pow((T-x[r-1]),3)/(6*h[r]))+(y[r-1]-((M[r-1]*h[r]*h[r])/6))*((x[r]-T)/h[r])+(y[r]-(M[r]*h[r]*h[r])/6)*(T-x[r-1])/h[i];
	cout<<S<<endl;
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
