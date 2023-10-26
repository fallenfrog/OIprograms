#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,m,ans;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> x >> y >> m;
	if(m%x==0 || m%y==0){
		cout << m;
		return 0;
	}
	for(int i=0;i*x<=m;i++){
		int t = m-x*i;
		int p = t%y;
		ans = max(m-p,ans);
	}
	cout << ans;
	
	return 0;
}
