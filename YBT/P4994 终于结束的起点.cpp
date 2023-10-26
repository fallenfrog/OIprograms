#include<bits/stdc++.h>
using namespace std;
int m;

int fib(int m){
	int a = 0,c = 1,cnt = 0;
	do{
		c = a+c;
		a = c-a;
		if(c>=m)	c -= m;
		cnt++;
	}while(a!=0 || c!=1);
	return cnt;
}

int main(){
	cin >> m;
	cout << fib(m);
	
	return 0;
}
