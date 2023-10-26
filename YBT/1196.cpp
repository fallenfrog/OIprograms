#include<bits/stdc++.h>
using namespace std;
int n;

int f(int n){
	if(n==1)	return 3;
	if(n==2)	return 7;
	return f(n-1)*2+f(n-2);
}

int main(){
	cin >> n;
	cout << f(n);
	
	return 0;
}
