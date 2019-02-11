#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	int n,i,j;
	double a[10][10];
	double t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cin>> a[i][j];
		}
	}	
	for(i=1;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
			if(j-i<0)
			{
				t=a[i][j]/a[j][j];
				cout<<t<<" ";
				for(int z=j;z<n+1;z++)
				{
					a[i][z]=a[i][z]-(a[j][z]*t);
				}
			}	
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
	return 0;
}


