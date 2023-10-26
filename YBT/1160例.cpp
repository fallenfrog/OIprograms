#include<iostream>
using namespace std;

void f(int n){
	cout << n%10;
	if(n>10){
		f(n/10);
	}
}

int main(){
	int n=0;
	cin >> n;
	f(n);
	return 0;
}
