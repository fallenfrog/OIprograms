#include<bits/stdc++.h>
#define mod 1000000
using namespace std;
int n,ans,t = 1;

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		t = t*i%mod;
		ans = (ans+t)%mod;
	}
	cout << ans;
	
	return 0;
}
