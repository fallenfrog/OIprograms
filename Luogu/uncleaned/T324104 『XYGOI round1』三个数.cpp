#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T,i,t;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		if(n==3){
			cout << 3 << '\n';
			continue;
		}
		i = 3,t = 3;
		while(++i){
			if(t<n && t*2>=n){
				cout << i << '\n';
				break;
			}
			t *= 2;
		}
	}
	
	return 0;
}
