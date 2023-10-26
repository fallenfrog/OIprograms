#include<iostream>
using namespace std;
long long m,n,maxx=-1000000,a[100],sum=0;


int main(){
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> a[i];
		if(a[i]>maxx){
			maxx = a[i];
		}
		sum += a[i];
	}
	for(int i=0;i<m;i++){
		if(a[i]==maxx){
			n++;
		}
	}
	cout << sum-maxx*n;
	
	return 0;
} 
