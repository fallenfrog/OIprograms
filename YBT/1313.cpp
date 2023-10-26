#include<bits/stdc++.h>
#define mod 12345
using namespace std;
int n,ans,dp1=9,dp2=1;

int pow(int b,int p){
	int ans = 1;
	while(p>0){
		if(p&1){
			ans *= b;
			ans %= mod;
		}
		b = b*b%mod;
		p >>= 1;
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i=2;i<n;i++){
		int t = dp1;
		dp1 = dp2+dp1*9;
		dp2 = t+dp2*9;
		dp1%=mod;
		dp2%=mod;
	}
	cout << dp1*8+dp2;
	
	return 0;
}
