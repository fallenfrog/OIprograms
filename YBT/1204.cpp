#include<bits/stdc++.h>
using namespace std;
int n,fn[31];

int f(int n){
	if(fn[n]!=0)	return fn[n];
	if(n==1 || n==2)	return fn[n] = n;
	return fn[n] = f(n-1)+f(n-2);
}

int main(){
	while(cin>>n){
		cout << f(n) << '\n';
	}
	
	return 0;
}
