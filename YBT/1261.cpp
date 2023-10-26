#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,d[1005],pre[1005];
bool vis[1005];
vector<int>	p[1005],w[1005],ans;

void dijkstra(){
	d[1] = 0;
	vis[1] = 1;
	for(int i=0;i<p[1].size();i++){
		d[p[1][i]] = w[1][i];
		pre[p[1][i]] = 1;
	}
	for(int u=1;u<n;u++){
		int m = 0;
		for(int i=2;i<=n;i++)
			if(!vis[i] && d[i]<d[m])
				m = i;
		vis[m] = 1;
		for(int i=0;i<p[m].size();i++)
			if(d[p[m][i]]>d[m]+w[m][i]){
				d[p[m][i]] = d[m]+w[m][i];
				pre[p[m][i]] = m;
			}
	}
}

int main(){
	cin >> n;
	int t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin >> t;
			if(t!=0){
				p[i].push_back(j);
				w[i].push_back(t);
			}
		}
	memset(d,INF,sizeof(d));
	memset(pre,-1,sizeof(pre));
	dijkstra();
	cout << "minlong=" << d[n] << endl;
	while(n!=-1){
		ans.push_back(n);
		n = pre[n];
	}
	for(int i=ans.size()-1;i>=0;i--)	cout << ans[i] << ' ';
	
	return 0;
}
