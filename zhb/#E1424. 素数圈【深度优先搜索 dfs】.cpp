#include<bits/stdc++.h>
using namespace std;
int T=1,n,ans[20];
bool isp[20],vis[20];

void dfs(int k){
	if(k==n){
		if(isp[ans[n]+1]){
			for(int j=1;j<=n;j++)
				cout << ans[j] << ' ';
			cout << '\n';
			ans[n] = 0;
		}
		return ;
	}
	for(int i=2;i<=n;i++){
		if(!vis[i] && isp[ans[k]+i]){
			ans[k+1] = i;
			vis[i] = 1;
			dfs(k+1);
			ans[k+1] = 0;
			vis[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	isp[2] = isp[3] = isp[5] = isp[7] = isp[11] = isp[13] = isp[17] = isp[19] = isp[23] = isp[29] = isp[31] = isp[37] = isp[41] = vis[1] = 1,ans[1] = 1;
//	while(cin >> n){
//		cout << "Case " << T++ << ":\n";
//		dfs(1);
//		cout << '\n';
//	}
	cin >> n;
	dfs(1);
	
	return 0;
}
