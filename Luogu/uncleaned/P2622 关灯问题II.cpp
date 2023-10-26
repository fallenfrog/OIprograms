#include<bits/stdc++.h>
using namespace std;
int n,m,p[12][102],cnt[1500];
bool vis[1500];

void bfs(){
	queue<int> q;
	vis[(1<<n)-1] = 1,cnt[(1<<n)-1]=0;
	q.push((1<<n)-1);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<m;i++){
			int tt = t;
			for(int j=0;j<n;j++)
				if((p[j][i]==1 && (tt>>j)&1) || (p[j][i]==-1 && !((tt>>j)&1)))	tt ^= 1<<j;
			if(!vis[tt]){
				cnt[tt] = cnt[t]+1;
				if(tt==0){
					cout << cnt[tt];
					return ;
				}
				vis[tt] = 1;
				q.push(tt);
			}
		}
	}
	cout << -1;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> p[j][i];
		}
	}
	bfs();

	return 0;
}

