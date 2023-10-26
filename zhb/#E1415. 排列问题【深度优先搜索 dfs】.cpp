#include<bits/stdc++.h>
using namespace std;
int n,m,ans[20];
bool vis[20];

void dfs(int x){
	if(x>m){
		for(int i=1;i<=m;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			ans[x] = i;
			dfs(x+1);
			vis[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	dfs(1);
	
	return 0;
}
