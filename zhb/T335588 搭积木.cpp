#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int n,a[1000002],s[1000002],m[1000002][2],cnt,l=1;//m[k][0]是k（包括）前最小， m[k][1]是k（不包括）后最小 

bool check(int idx){
	return m[idx-1][1]-s[idx-1]>=0 && s[n]-s[idx-1]+m[idx-1][0]>=0;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);	cout.tie(nullptr);
	cin >> n;	m[0][0] = m[n][1] = 1e18;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
		m[i][0] = min(s[i],m[i-1][0]);
	}
	for(int i=n-1;i>=0;i--){
		m[i][1] = min(s[i+1],m[i+1][1]);
	}
//	for(int i=1;i<=n;i++){
//		cout << m[i][0] << ' ' << m[i-1][1] << '\n';
//	}
	for(int i=1;i<=n;i++){
		if(check(i)){//包括i往后和加不包括i往前和 
//			cout << i << endl;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
/*
input:
9
4 -7 8 -9 3 6 7 -2 9
*/
