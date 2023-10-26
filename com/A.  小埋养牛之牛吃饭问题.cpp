#include<bits/stdc++.h>
using namespace std;
int k,n,m,u,v,h[1002],cnt,num[1002],ans,ma[1002];
bool can[1002][1002],vis[1002],t[1002];

void update(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i || !can[i][j])	continue;
			for(int k=1;k<=n;k++){
				can[i][k] |= can[j][k];
			}
		}
	}
}

int main(){
	memset(h,-1,sizeof(h));
	cin >> k >> n >> m;
	for(int i=1;i<=k;i++){
		int tt;cin >> tt;
		if(!vis[tt]){
			vis[tt] = 1;
			ma[cnt++] = tt;
		}
	}
	for(int i=1;i<=m;i++){
		cin >> u >> v;
		can[u][v] = 1;
	}
	for(int i=1;i<=n;i++){
		can[i][i] = 1;
	}
	update();	update();
	for(int i=1;i<=n;i++)	t[i] = 1;
	for(int i=0;i<cnt;i++){
		for(int j=1;j<=n;j++){
			t[j] &= can[ma[i]][j];
		}
	}
	for(int i=1;i<=n;i++)	if(t[i])	ans++;
	cout << ans;

	return 0;
}

