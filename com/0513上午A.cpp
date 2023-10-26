#include<bits/stdc++.h>
#define INF 0x3f3f3f3f 
using namespace std;
int n,m,ans=INF;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		ans = min(ans,w);
	}
	if(ans&1)	cout << ans << "/2";
	else		cout << ans/2 << "/1";
	
	return 0;
}
