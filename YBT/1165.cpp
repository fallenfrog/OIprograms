#include<bits/stdc++.h>
using namespace std;

double h(int n,int x){
	if(n==0) return 1;
	if(n==1) return 2*x;
	if(n>1) return 2*x*h(n-1,x)-2*(n-1)*h(n-2,x);
}

int main(){
	int n,x;
	cin >> n >> x;
	printf("%.2lf",h(n,x));
	
	return 0;
}
