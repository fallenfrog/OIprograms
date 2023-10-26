#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,cnt,root=1,d[1000002],num[1000002],dep,e;
bool vis[1000002];
vector<int> p[1000002],m[1000002];

void dfs(int fa){
	vis[fa] = 1;
	if(p[fa].size()>1){
		for(int i=0;i<p[fa].size();i++){
			int t = p[fa][i];
			if(!vis[t]){
				d[t] = d[fa]+1;
				m[d[t]].push_back(t);
				num[d[t]]++;
				dfs(t);
			}
		}
	}else{
		dep = max(dep,d[fa]);
	}
}

void search(int a,int b){
	if(a==b){
		if(!vis[a]){
			cout << a << '\n';
			vis[a] = 1;
			num[d[a]]--;
			cnt++;
			cout << "cnt=" << cnt << '\n';
		}
		return ;
	}
	vis[a] = vis[b] = 1;
	num[d[a]]--;	num[d[b]]--;
	for(int i=0;i<p[a].size();i++){
		cout << a << ' ';
		int t = p[a][i];
		if(d[t]<d[a]){
			a = t;
			break;
		}
	}
	for(int i=0;i<p[b].size();i++){
		cout << b << ' ';
		int t = p[b][i];
		if(d[t]<d[b]){
			b = t;
			break;
		}
	}
	search(a,b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	d[1] = num[1] = 1;	dfs(1);
	memset(vis,0,sizeof(vis));
	cout << "dep=" << dep << '\n';
	for(int i=dep;i>0;i--){
		for(int j=0;j<m[i].size();j++){
			int t = m[i][j];
			if(!vis[t]){
				num[i]--;
				vis[t] = 1;
				if(num[i]==0 && e==0){
					cout << "single " << t << '\n';
					for(int i=0;i<p[t].size();i++){
						int tt = p[t][i];
						if(d[tt]<d[t] && vis[tt]){
							cnt++;
							break;
						}
					}
					if(d[t]==1)	cnt++;
					continue;
				}
				if(e!=0){
					cout << "e=" << e << " t=" << t << '\n';
					search(e,t);
					e = 0;
				}
				else{
					e = t;
					cout << "e=" << e << " num=" << num[i] << '\n';
				}
			}
		}
	}
	cout << cnt;
	cout << '\n' << vis[4];
	
	return 0;
}
/*
input:
16
1 2
1 3
2 4
2 5
2 6
3 7
3 8
5 9
5 10
6 11
7 12
7 13
8 14
12 15
13 16
*/
