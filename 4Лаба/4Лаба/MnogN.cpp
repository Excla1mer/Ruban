#include <iostream>
#include <math.h>

using namespace std;
float x[3]={0.5,0.5,0.5},x1[3];
float y[3];
float W[3][3];
float F[2];
float e=0.1;
float f1(float x,float y,float z)
{
	return (pow(x,2)+pow(y,2)+pow(z,2));
}
float f2(float x,float y,float z)
{
	return (2*pow(x,2)+pow(y,2)-4*z);
}
float f3(float x,float y,float z)
{
	return (3*pow(x,2)-4*y+pow(z,2));
}
float f4(float x,float y,float z)
{
	return (3*pow(x,2)-4*y+pow(z,2));
}
float w1(float x,float y,float z)
{
	return (2*x);
}
float w2(float x,float y,float z)
{
	return (2*y);
}
float w3(float x,float y,float z)
{
	return (2*z);
}
float w4(float x,float y,float z)
{
	return (4*x);
}
float w5(float x,float y,float z)
{
	return (2*y);
}
float w6(float x,float y,float z)
{
	return (-4);
}
float w7(float x,float y,float z)
{
	return (6*x);
}
float w8(float x,float y,float z)
{
	return (-4);
}
float w9(float x,float y,float z)
{
	return (2*z);
}
float Gays();
int main()
{
	int i,j,iter=0;
	float R[2],E;
	setlocale(LC_ALL, "Russian");
	do
	{
		iter++;
		W[0][0]=w1(x[0],x[1],x[2]);
		W[0][1]=w2(x[0],x[1],x[2]);
		W[0][2]=w3(x[0],x[1],x[2]);
		W[1][0]=w4(x[0],x[1],x[2]);
		W[1][1]=w5(x[0],x[1],x[2]);
		W[1][2]=w6(x[0],x[1],x[2]);
		W[2][0]=w7(x[0],x[1],x[2]);
		W[2][1]=w8(x[0],x[1],x[2]);
		W[2][2]=w9(x[0],x[1],x[2]);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<W[i][j]<<"\t";
			}
			cout<<"\n";
		}
		Gays();
		x1[0]=x[0]-y[0];
		x1[1]=x[1]-y[1];
		cout<<"x[0]= "<<x[0]<<" x[1]= "<<x[1]<<endl;
		cout<<"x1[0]= "<<x1[0]<<" x1[1]= "<<x1[1]<<endl;
		R[0]=fabs(x1[0]-x[0]);
		R[1]=fabs(x1[1]-x[1]);
		x[0]=x1[0];
		x[1]=x1[1];
		cout<<"R[0]= "<<R[0]<<" R[1]= "<<R[1]<<endl;
		if(R[0]<R[1])
			E=R[1];
		else
			E=R[0];
	}while(iter<3);
	cout<<"x[0]= "<<x[0]<<"  x[1]= "<<x[1]<<endl;
	cout<<"iterac="<<iter<<endl;
	return 0;
}
float Gays()
{
	int n=3,i,j,rememb_str,rememb_elem;
	bool f=true,b=false;
	double a[10][10],Mat_x[100];
	double t,max;
	cout<<"*********************\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=W[i][j];
		}
		a[i][3]=x[i];
	}	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}	
	cout<<"---------------------\n";
	/*for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				b=false;
				max=fabs(a[i][j]);
				for(int z=i+1;z<n;z++)
				{
					if(max<fabs(a[z][j]))
					{
						max=fabs(a[z][j]);
						rememb_str=z;
						b=true;
					}
				}
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
	}*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"+++++++++++++++++++++\n";
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
			}	
		}
	}
	for(i=n-1;i>=0;i--)
	{
		Mat_x[i]=a[i][n]/a[i][i];
		for(j=n-1;j>i;j--)
		{		
			Mat_x[i]=Mat_x[i]-a[i][j]*Mat_x[j]/a[i][i];		
		}
	}
	for(int z=0;z<n;z++)
	{
		if(a[z][z]==0)
		{
			f=false;
		}
	}
	cout<<"<><><><><><><><><><>\n";
	//if(f==true)
	//{
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
			y[i]=Mat_x[i];
		}
		cout<<"\n";
	//}
	/*else
	{
		cout<<"Matricha virogdennaya\n";
	}
	cout<<"<><><><><><><><><><>\n";*/
}

