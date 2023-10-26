#include<bits/stdc++.h>
using namespace std;
int n,mj=1e9+7,t,sum;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		if(t&1 && mj>t)	mj = t;
		sum += t;
	}
	if(sum&1)	sum -= mj;
	if(sum)	cout << sum;
	else	cout << "NIESTETY";

	return 0;
}

