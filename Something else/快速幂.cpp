#include<bits/stdc++.h>
using namespace std;
int a=1,b,k;

int main(){
	cin >> b >> k;
	for(;k;k>>=1){
		if(k&1)	a *= b;
		b *= b;
	}
	cout << a;
	
	return 0;
}
