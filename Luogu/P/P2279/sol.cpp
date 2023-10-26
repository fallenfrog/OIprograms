#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P2279";
const int N = 1e3 + 2;

int n, h[N], k, u, fa[N], ans;
bool cvd[N];
struct edge{
	int v, nxt;
}e[N << 1];

#define PII pair<int, int>
#define dep first
#define idx second
#define mp make_pair
priority_queue <PII> q;

void dfs(int x, int d){
	q.push(mp(d, x));
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa[x])  continue;
		fa[v] = x;
		dfs(v, d + 1);
	}
}

void color(int x, int la, int rem){
	cvd[x] = 1;
	if(!rem)  return ;
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == la)  continue;
		color(v, x, rem - 1);
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 2; i <= n; i ++){
		cin >> u;
		e[++ k] = {i, h[u]}, h[u] = k;
		e[++ k] = {u, h[i]}, h[i] = k;
	}
	fa[1] = 1;  dfs(1, 0);
	while(!q.empty()){
		int t = q.top().idx;  q.pop();
		if(cvd[t])  continue;
		int gf = fa[fa[t]];
		color(gf, gf, 2);
		ans ++;
	}
	cout << ans;

	return 0;
}
