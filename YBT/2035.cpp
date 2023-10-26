#include<iostream>
using namespace std;
int a[1000],n,t;

int main(){
	cin >> n;
	cin >> a[n-1];
	for(int i=0;i<n-1;i++){
		cin >> a[i];
		cout << a[i] << ' ';
	}
	cout << a[n-1];
	
	return 0;
} 
