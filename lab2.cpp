#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
	int i,j,n,f,rememb_elem,rememb_str,eter=0,iter=0;
	bool b=true,t=false;
	double a[20][20],e,x1[20],x2[20],x3[20],x4[20],x[20],max=-1,c,sum=0,maxs=0;
	ifstream in("input.txt");
	cin>>n>>e;
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			in >> a[i][j];
		}
	}	
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"---------------------------------------\n";
	for(i=0;i<n;i++)		//Перестановка строк по убыванию диагонального эл-та
	{	
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				t=false;
				maxs=fabs(a[i][j]);
				for(int z=i+1;z<n;z++)
				{
					if(maxs<fabs(a[z][j]))
					{
						max=fabs(a[z][j]);
						rememb_str=z;
						t=true;
					}
				}
				if(t==true)
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
	for(i=0;i<n;i++){			//Проверка диагонального преобладания 
		for(j=0;j<n;j++){
			if(i==j)
				maxs=a[i][j];
			else
				sum+=a[i][j];
		}
		if(fabs(maxs)-abs(sum)>0)
		{
			b=true;
		}
		else
		{
			b=false;
			break;
		}
		sum=0;
	}
	cout<<"------------------------------------------\n";
if(b==true)
{
	for(i=0;i<n;i++){  //Создание матрицы С
		for(j=0;j<n;j++){
			if(i!=j){
				a[i][j]=(a[i][j]/a[i][i])*-1;
			}
		}
		a[i][n]=a[i][n]/a[i][i];
		x1[i]=a[i][n];
		a[i][i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			printf("%.2f\t",a[i][j]);
		}
		cout<<"\n";
	}
	cout<<"-----------------------------------------\n\n";
	
	for(i=0;i<n;i++)
	{
		x3[i]=0;
		x4[i]=0;
	}
	do{		//Метод Зейделя
		iter++;
		max=1;
		for(i=0;i<n;i++){
			x[i]=0;
			for(j=0;j<n;j++){
				x[i]+=(a[i][j]*-1)*x3[j];
			}
			x3[i]=a[i][n]-x[i];
		//	printf("[%.2f]{%.2f}",x3[i],x[i]);
		}
		if(iter>0)
		{
			max=-1;
			for(i=0;i<n;i++){
				c=x4[i]-x3[i];
				//printf("%.2f><%.2f\n",fabs(c),max);
				if(fabs(c) > max)
					max=fabs(c);
			}
		}
		for(i=0;i<n;i++)
		{
			x4[i]=x3[i];
		}	
	}while(max>e);
	do{ //Метод простых итераций
		eter++;
		max=-1;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				x2[i]+=a[i][j]*x1[j];
			}
			x2[i]+=a[i][n];
		}
		for(i=0;i<n;i++){
			c=x2[i]-x1[i];
			//printf("%.2f><%.2f\n",fabs(c),max);
			if(fabs(c) > max)
				max=fabs(c);
			for(j=0;j<n;j++){
				//printf("%.2f|%.2f\n",x2[j],x1[j]);
			}	
		}
		for(i=0;i<n;i++)
		{
			x1[i]=x2[i];
			x2[i]=0;
		}		
	}while(max>e);
	printf("\n\n------------------\n");
	printf("Prostie iterac\n");
	for(i=0;i<n;i++){
		printf("%f\t",x1[i]);
	}
	cout<<"\nKol-vo iterac = "<<eter+1<<endl;
	cout<<"\n";
	printf("Metod Zeidela\n");
	for(i=0;i<n;i++){
		printf("%f\t",x4[i]);
	}
	cout<<"\nKol-vo iterac = "<<iter<<endl;
	
}
else
{
	cout<<"Net yslovia diag preoblod.\n";
}
	return 0;
}
