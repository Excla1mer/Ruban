#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


int main()
{
	int n,i,j,rememb_str,rememb_elem;
	bool f=true,b=false;
	double a[10][10],Mat_x[100];
	double t,max;
	ifstream in("input2.txt");
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			in >> a[i][j];
		}
	}
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
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				b=false;
				max=fabs(a[i][j]);
	//			cout<<"<"<<max<<">\n";
				for(int z=i+1;z<n;z++)
				{
					if(max<fabs(a[z][j]))
					{
						max=fabs(a[z][j]);
						rememb_str=z;
						b=true;
					}
				}
	//			cout<<"|"<<max<<"|"<<rememb_str<<"|\n";
				if(b==true)
				{
				
					for(int z=0;z<n+1;z++)
					{
						rememb_elem=a[i][z];
						a[i][z]=a[rememb_str][z];
						a[rememb_str][z]=rememb_elem;
					}
				
					for(int q=0;q<n;q++)
					{
						for(int w=0;w<n+1;w++)
						{
							cout<<a[q][w]<<"\t";
						}
						cout<<"\n";
					}
				}
			}	
		}
	}
	cout<<"\n\n-----------------------\n\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(i=0;i<n;i++)
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
					cout<<"----------------------------------------\n";
				for(int w=0;w<n;w++){
					for(int y=0;y<n+1;y++)
					{
						cout<<a[w][y]<<"\t";
					}
					cout<<endl;
				}
			}	
		}
	
	}
	for(i=n-1;i>=0;i--)
	{
		Mat_x[i]=a[i][n]/a[i][i];
		//cout<<"{"<<a[i][n]<<","<<a[i][i]<<"}";
		//cout<<"|"<<Mat_x[i]<<"|";
		for(j=n-1;j>i;j--)
		{
			//cout<<"\n";
			//cout<<"{"<<Mat_x[i]<<","<<a[i][j]<<","<<Mat_x[j]<<","<<a[i][i]<<"}";
			Mat_x[i]=Mat_x[i]-a[i][j]*Mat_x[j]/a[i][i];
			//cout<<"<"<<Mat_x[i]<<">";
		}
		//cout<<"\n";
	}
	cout<<"\n";
	for(int z=0;z<n;z++)
	{
		if(a[z][z]==0)
		{
			f=false;
		}
	}
	if(f==true)
	{
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


