#include<bits/stdc++.h>
using namespace std;
int a,b;

int main(){
	cin >> a >> b;
	cout << a << '/' << b << '=' << a/b << '.';
	int p = a%b;
	if(p==0){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=20;i++){
		if(p==0)	return 0;
		p *= 10;
		cout << p/b;
		p %= b;
	}
	
	return 0;
}
