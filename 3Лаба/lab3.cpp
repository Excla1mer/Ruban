#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
float E,a,b,c,e,a1,b1,x1,x2;
bool f=true;
float F(float x)
{
	return (x*x-x-3);
}
float F1(float x)
{
	return (2*x-1);
}
float mpd()
{
	c=(a+b)/2;
	if(F(c)==0)
	{
		f=false;
		return c;
	}
	else
	{
			if(F(a)*F(c)<0)
		{
			b=c;	
		}
		else
		{
			a=c;
		}
		E=fabs(b-a)/2;
	}
	
}
float mx()
{
	c=(a*F(b)-b*F(a))/(F(b)-F(a));
	if(F(c)==0)
	{
		f=false;
		if(F(a)*F(c)<0)
		{
			b=c;
		}
		else
		{
			a=c;
		}
		return c;
	}
	else
	{
		if(F(a)*F(c)<0)
		{
			b=c;
		}
		else
		{
			a=c;
		}
		return c;
	}
}
float MN()
{
	c-=F(c)/F1(c);
	return c;
}
int main(){
	int i;
	cout<<"vvedite granici\n";
	cin>>a1>>b1;
	cout<<"Vvedite tochnost'\n";
	cin>>e;
	a=a1;
	b=b1;
	cout<<"MPD:\n";
	do{
		mpd();
		if(f==false)
			break;
	}
	while(E>=e);
	if(f==true)
		cout<<"a="<<a<<" b="<<b<<endl;
	else
		cout<<"Tochney koren'\n";
	cout<<mpd()<<"\n";
	cout<<"MX:\n";
	a=a1;
	b=b1;
	x1=mx();
	do
	{
		x2=mx();
		E=fabs(x2-x1);
		x1=x2;
	}
	while(E>=e);
	if(f==true)
		cout<<"a="<<a<<" b="<<b<<endl;
	else
		cout<<"Tochney koren'\n";
	cout<<mx()<<endl;
	cout<<"MN:\n";
	a=a1;
	b=b1;
	c=a;
	for(i=0;i<10;i++)
	{
		MN();
	}
	cout<<c<<endl;
	return 0;
}
