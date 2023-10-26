#include<bits/stdc++.h>
#define int long long
#define mod 32767
using namespace std;
int n,m,p[1000005];

int pell(int m){
	if(p[m]==0){
		if(m==1 || m==2){
			p[m] = m;
			return p[m];
		}
		p[m] = (pell(m-1)*2+pell(m-2))%mod;
	}
	return p[m];
}

signed main(){
	cin >> n;
	while(n--){
		cin >> m;
		cout << pell(m) << endl;
	}
	
	return 0;
}
