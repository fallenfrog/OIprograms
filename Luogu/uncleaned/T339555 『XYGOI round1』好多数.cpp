#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[5002],b[5002],t[5002],cnt=1,k,m,q;

bool check(int n){
	if(n==a[1])	return 1;
	if(n%a[1])	return 0;
	return check(n/a[1]);
}

signed main(){
	while(cin >> a[cnt] >> b[cnt]){
		if(a[cnt]==0 && b[cnt]==0)	break;
		cnt++;
	}cnt--;
	if(cnt==1){
		t[b[1]-1] = t[b[1]] = 1;
		for(int i=b[1]-2;i>0;i--){
			t[i] = t[i+1] << 1;
			if(t[i]>=mod)	t[i] -= mod;
		}
		cin >> q;
		while(q--){
			cin >> k;
			if(!check(k)){
				cout << "0 ";
				continue;
			}m = -1;
			while(k){
				k /= a[1];
				m++;
			}
			cout << t[m] << ' ';
		}
	}
	
	return 0;
}
