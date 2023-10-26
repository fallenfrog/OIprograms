#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,a[1000002],tt[1000002];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("champagne.in","r",stdin);
//	freopen("champagne.out","w",stdout);
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}cin >> a[0];	sum += a[0];
	int ave = sum/n,t = 0;
	sum = 0;
	for(int i=0;i<n;i++)	a[i] -= ave;
	tt[0] = a[0];
	for(int i=0;i<n;i++){
		if(a[i]>0)	sum += a[i];
	}
	cout << sum;

	return 0;
}

