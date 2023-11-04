#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "CF1774E";
const int N = 2e5 + 2;

int n, m, h[N], k, u, v, d[N], md[N][2], ans;
bool im[N][2];
struct edge{
	int v, nxt;
}e[N << 1];

bool dfs(int x, int fa){
	d[x] = d[fa] + 1;
	if(im[x][0])  md[x][0] = d[x];
	if(im[x][1])  md[x][1] = d[x];
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		dfs(v, x);
		md[x][0] = max(md[x][0], md[v][0]);
		md[x][1] = max(md[x][1], md[v][1]);
	}
	if(!md[x][0] && md[x][1] - m < d[x])  ans -= 2;
	if(!md[x][1] && md[x][0] - m < d[x])  ans -= 2;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i < n; i ++){
		cin >> u >> v;
		e[++ k] = {v, h[u]}, h[u] = k;
		e[++ k] = {u, h[v]}, h[v] = k;
	}
	cin >> k;  for(int i = 1; i <= k; i ++){ cin >> v;  im[v][0] = 1;}
	cin >> k;  for(int i = 1; i <= k; i ++){ cin >> v;  im[v][1] = 1;}
	ans = (n - 1) << 2;  dfs(1, 0);
	cout << ans;

	return 0;
}
