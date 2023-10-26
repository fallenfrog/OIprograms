#include<iostream>
#include<cmath>
using namespace std;
long long m,n,maxx=-1000000,a[100],sum=0;

bool complete(int n){
	for(int i=2;i<n;i++){
		if(n%i==0){
			sum += i;
		}
	}
	if(sum==n) return 1;
	else return 0;
}

int main(){
	cin >> m;
	for(int i=2;i<=m;i++){
		sum = 1;
		if(complete(i)) cout << i << endl;
	}
	
	return 0;
} 
