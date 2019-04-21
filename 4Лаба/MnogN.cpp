#include <iostream>
#include <math.h>

using namespace std;
double x[2]={2,1},x1[2];
double y[2];
double W[2][2];
double F[2];
double e=0.00001;
double f1(double x,double y)
{
	return (2*pow(x,2)+pow(y,2)-1);
}
double f2(double x,double y)
{
	return (pow(x,3)+6*pow(x,2)*y-1);
}
double w1(double x,double y)
{
	return (4*x);
}
double w2(double x,double y)
{
	return (2*y);
}
double w3(double x,double y)
{
	return (3*pow(x,2)+12*x*y);
}
double w4(double x,double y)
{
	return (6*x*x);
}
/*double f1(double x,double y)
{
	return (pow(x,2)+pow(y,3)-5);
}
double f2(double x,double y)
{
	return ((x/y)-3);
}
double w1(double x,double y)
{
	return (2*x);
}
double w2(double x,double y)
{
	return (3*pow(y,2));
}
double w3(double x,double y)
{
	return (1/y);
}
double w4(double x,double y)
{
	return (x/pow(y,2)*(-1));
}*/
double Gays();
int main()
{
	int i,j,iter=0;
	double E;
	setlocale(LC_ALL, "Russian");
	
	do
	{
		if(iter!=0)
		{
			x[0]=x1[0];
			x[1]=x1[1];
		}
		W[0][0]=w1(x[0],x[1]);
		W[0][1]=w2(x[0],x[1]);
		W[1][0]=w3(x[0],x[1]);
		W[1][1]=w4(x[0],x[1]);
		F[0]=f1(x[0],x[1]);
		F[1]=f2(x[0],x[1]);
		cout<<"Матрица Якоби:\n";
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				cout<<W[i][j]<<"\t";
			}
			cout<<"\n";
		}
		Gays();
		//y[0]=f1(x[0],x[1])/w1(x0[0],x0[1]);
		x1[0]=x[0]-y[0];
		x1[1]=x[1]-y[1];
		cout<<"X[0]="<<x[0]<<" X[1]="<<x[1]<<endl;
		cout<<"x1[0]="<<x1[0]<<" x1[1]="<<x1[1]<<endl;
		cout<<"Y[0]="<<y[0]<<" Y[1]="<<y[1]<<endl;
		//cout<<"x[0]= "<<x[0]<<" x[1]= "<<x[1]<<endl;
		
		iter++;
		cout<<"\n************************\n";
	}while(fabs(x[0]-x1[0])>e || fabs(x[1]-x1[1])>e);
	//cout<<"x[0]= "<<x[0]<<"  x[1]= "<<x[1]<<endl;
	F[0]=f1(x1[0],x1[1]);
	F[1]=f2(x1[0],x1[1]);
	cout<<"F[0]="<<F[0]<<endl;
	cout<<"F[1]="<<F[1]<<endl;
	cout<<"iter="<<iter<<endl;
	
	return 0;
}
double Gays()
{
	int n=2,i,j,rememb_str,rememb_elem;
	bool f=true,b=false;
	double a[10][10],Mat_x[100];
	double t,max;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=W[i][j];
		}
		a[i][2]=F[i];
	}
	cout<<"Матрица Гауса:\n";	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
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
	for(i=n-1;i>=0;i--)
	{
		Mat_x[i]=a[i][n]/a[i][i];
		
		for(j=n-1;j>i;j--)
		{
			
			Mat_x[i]=Mat_x[i]-a[i][j]*Mat_x[j]/a[i][i];
			
			
		}
	
		y[i]=Mat_x[i];
	}

}

