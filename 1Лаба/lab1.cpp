#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int main()
{
	int n,i,j;
	bool f=true;
	double a[10][10],Mat_x[100];
	double t;
	ifstream in("input.txt");
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			in >> a[i][j];
		}
	}
	for(i=1;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				if(a[i][j]==0)
				{
					f=false;
				}
			}
		}
	}
	if(f==true)
	{
		for(i=n-1;i>=0;i--)
		{
			Mat_x[i]=a[i][n]/a[i][i];
			for(j=n-1;j>i;j--)
			{
				Mat_x[i]=Mat_x[i]-a[i][j]*Mat_x[j]/a[i][i];
			}
		}
		cout<<"\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n+1;j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
		for(i=0;i<n;i++)
		{
			cout<<Mat_x[i]<<"\t";
		}
	}
	else
	{
		cout<<"Matricha virogdennaya\n";
	}
	
	return 0;
}


