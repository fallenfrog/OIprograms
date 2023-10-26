#include<iostream>
using namespace std;
int a[10];
double s;

int main(){
	for(int i=0;i<10;i++){
		cin >> a[i];
		if(i==0) s += a[i]*28.9;
		if(i==1) s += a[i]*32.7;
		if(i==2) s += a[i]*45.6;
		if(i==3) s += a[i]*78;
		if(i==4) s += a[i]*35;
		if(i==5) s += a[i]*86.2;
		if(i==6) s += a[i]*27.8;
		if(i==7) s += a[i]*43;
		if(i==8) s += a[i]*56;
		if(i==9) s += a[i]*65;
	}
	
	printf("%.1lf",s);

	return 0;
} 
