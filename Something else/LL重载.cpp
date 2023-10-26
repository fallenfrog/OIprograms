#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;

long long operator* (long long a,long long b){
	int ans=0;
	for(;b;b>>=1){
		if(b&1)	ans = (ans+a)%mod;
		a >>= 1;
		if(a>=mod)	a -= mod;
	}
	return ans;
}

int main(){
	long long a,b;
	cin >> a >> b;
	cout << a*b;

	return 0;
}

