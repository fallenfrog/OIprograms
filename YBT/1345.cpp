#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int k,n,m,num[801],f[801][801];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> k >> n >> m;
	for(int i=1;i<=k;i++){
		int t;	cin >> t;
		num[t]++;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		f[a][b] = f[b][a] = c;
	}
	for(int i=1;i<=n;i++)	f[i][i] = 0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]!=INF && f[k][j]!=INF && f[i][k]+f[k][j]<f[i][j]){
					f[i][j] = f[i][k]+f[k][j];
				}
			} 
		}
	}
	int ans = INF;
	for(int i=1;i<=n;i++){
		int t = 0;
		for(int j=1;j<=n;j++){
			t += num[j]*f[i][j];
		}
		ans = min(ans,t);
	}
	cout << ans;
	
	return 0;
}
