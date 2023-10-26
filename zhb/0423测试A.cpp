#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mod 1000000
using namespace std;
int n,a[1000007];

int jc(int n){
	if(n==0)	return 1;
	return (n*(jc(n-1)%mod))%mod;
}

int main(){
	a[0] = 1;
	cin >> n;
//	jc(n);
	int sum = 0;
	for(int i=1;i<=n;i++){
//		a[i]=(i*a[i-1])%mod;
		sum += jc(i);
		sum %= mod;
	}
	cout << sum;
	
	return 0;
}
