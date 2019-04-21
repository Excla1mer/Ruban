#include <iostream>
#include <math.h>
using namespace std;
double F(double x)
{
	return (1/x);
}
double Fact(double n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return Fact(n-1)*n;
	}
}
double Lagranj(double M[][100],double n,double x,double w,double x1)
{
	double q=1,e=1,sum=0;
	for(int i=x1;i<=n+x1;i++)
	{
		if(i<=n+x1)
		{
			for(int j=x1;j<=n+x1;j++)
			{
				if(i!=j)
				{
					q*=(x-M[j][0]);
					e*=(M[i][0]-M[j][0]);
				}
			}
			sum+=M[i][1]*q/e;
			q=1,e=1;
		}
		else
		{
			sum+=0;
		}
	}
	return sum;
}
double Eitken(double M[][100],double x,double w)
{
	double P[100];
	for(int j=0;j<w;j++)
	{
		P[j]=M[j][1];
		//cout<<"P["<<0<<"]="<<P[j]<<endl;
	}
	for(int i=1;i<w;i++)
	{
		for(int j=0;j<w-i;j++)
		{
			P[j]=(P[j]*(x-M[j+i][0])-P[j+1]*(x-M[j][0]))/(M[j][0]-M[j+i][0]);
			//cout<<"P["<<i<<"]="<<P[j]<<endl;
		}
	}
	return P[0];
}
double Niuton(double M[][100],double x,double w,double h)
{
	double P=M[0][1],q=(x-M[0][0])/h,q1=q;
	int i,j;
	for(i=0;i<w-1;i++)
	{
		q=(x-M[0][0])/h;
		for(j=1;j<=i;j++)
			q*=(q1-j);
		P+=M[0][2+i]/Fact(i+1)*q;
	}
	return P;
}
int main()
{
	double a=1,b=4,h=0.5,n=3,w=(b-a)/h,x=1.44,z,x1=a;
	double Matrix[100][100];
	int i,j;
	for(i=0;i<=w;i++)
	{
		Matrix[i][0]=a;
		Matrix[i][1]=F(a);
		a+=h;
	}
	int t=w;
	int r=2;
	do
	{
		for(i=0;i<t;i++)
		{
			Matrix[i][r]=Matrix[i+1][r-1]-Matrix[i][r-1];
		}
		t--;
		r++;
	}while(t!=0);
	a=a-h*(w+1);

	for(i=0;i<=w;i++)
	{
		for(j=0;j<r;j++)
		{
			if(Matrix[i][j]==0)
			{
				//cout<<"|";
				printf("|%2.5f\t",Matrix[i][j]);
			}
			else
				printf("|%2.5f\t",Matrix[i][j]);
				//cout<<"|"<<Matrix[i][j]<<"\t|";
		}
		cout<<endl;
	}
	cout<<"-------------------\n";
	for(z=a;z<=b;z+=h/2)
	{
		cout<<z<<"\t|\t"<<Lagranj(Matrix,n,z,w,x1)<<"\t|\t"<<F(z)<<"\n";
		if(z>x1+h)
		{
			x1+=h;
		}
	}
	cout<<"--------------------\n";
	for(z=a;z<=b;z+=h/2)
	{
		cout<<z<<"\t|\t"<<Eitken(Matrix,z,w)<<"\t|\t"<<F(z)<<"\n";
	}
	cout<<"--------------------\n";
	for(z=a;z<=b;z+=h/2)
	{
		cout<<z<<"\t|\t"<<Niuton(Matrix,z,w,h)<<"\t|\t"<<F(z)<<"\n";
	}
	
	return 0;
}
