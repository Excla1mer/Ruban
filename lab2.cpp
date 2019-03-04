#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
	int i,j,n,f;
	double a[20][20],e,x1[20],x2[20],max=-1,c;
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
	for(i=0;i<n;i++){
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
	do{
		max=-1;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				x2[i]+=a[i][j]*x1[j];
			}
			x2[i]+=a[i][n];
		}
		for(i=0;i<n;i++){
			c=x2[i]-x1[i];
			printf("%.2f><%.2f\n",fabs(c),max);
			if(fabs(c) > max)
				max=fabs(c);
			for(j=0;j<n;j++){
				printf("%.2f|%.2f\n",x2[j],x1[j]);
			}	
		}
		for(i=0;i<n;i++)
		{
			x1[i]=x2[i];
			x2[i]=0;
		}
		cout<<max<<"\n";
			
	}while(max>e);
	printf("\n\n------------------\n");
	for(i=0;i<n;i++){
		printf("%f\t",x1[i]);
	}
	return 0;
}
