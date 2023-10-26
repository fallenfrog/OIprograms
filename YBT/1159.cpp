#include<iostream>
using namespace std;

int f(int a,int b,int n){
	if(n==1){
		return a;
	}else{
		return f(b,a+b,n-1);
	}
}

int main(){
	int n;
	cin >> n;
	cout << f(0,1,n);
	return 0;
} 
