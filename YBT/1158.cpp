#include<iostream>
using namespace std;

long long sigma(long long n){
	if(n==0){
		return 0;
	}
	else return n+sigma(n-1);
}

int main(){
	long long n=0;
	cin >> n;
	cout << sigma(n);
	return 0;
}
