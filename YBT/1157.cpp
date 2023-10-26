#include<iostream>
#include<cmath>
using namespace std; 

bool ss(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	for(int i=6;i<101;i++){
		for(int j=3;j<=i/2;j+=2){
			if(ss(j)&&ss(i-j)){
				printf("%d=%d+%d\n",i,j,i-j);break;
			}
		}
	}
	return 0;
}
