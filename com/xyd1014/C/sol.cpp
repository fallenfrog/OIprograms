#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 1e9 + 7;
int n, m, c;

namespace zip{
	const int N = 22;
	int d[N][N], a[N], b[N], ans[N], u, v, w, cnt;
	int sum[1 << 20], temp[1 << 20][N], p[1 << 20];
	
	void main(){
		for(int i = 0; i < n; i ++)  cin >> a[i];
		for(int i = 0; i < c; i ++)  cin >> b[i];
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++)
				d[i][j] = INF;
			ans[i + 1] = INF;
		}
		for(int i = 1; i <= m; i ++){
			cin >> u >> v >> w;
			d[u][v] = d[v][u] = min(d[u][v], w);
		}
		for(int i = 0; i < n; i ++)  d[i][i] = 0, ans[1] = min(ans[1], a[i] + b[i]);
		for(int i = 0; i < n; i ++){
			
		}
		for(int i = 1; i <= n; i ++)  cout << ans[i] << ' '; 
	}
};

namespace bf{
	const int N = 1e5 + 2;
	int a[N], b[N], h[N], u, v, w, k, d[N];
	bool vis[N];
	struct edge{
		int v, w, nxt;
	}e[N * 6];
	
	struct node{
		int d, idx;
		bool operator > (const node& other) const{
			return d > other.d;
		}
	};
	priority_queue <node, vector<node>, greater<node> > q;
	
	void dijkstra(int s){
		for(int i = 1; i <= n; i ++)  d[i] = INF;
		d[s] = 0;  q.push(node{0, s});
		while(!q.empty()){
			int t = q.top().idx;  q.pop();
			if(vis[t])  continue;  vis[t] = 1;
			for(int i = h[t]; i; i = e[i].nxt){
				int v = e[i].v, w = e[i].w;
				if(d[v] > d[t] + w){
					d[v] = d[t] + w;
					q.push(node{d[v], v});
				}
			}
		}
	}
	
	void main(){
		for(int i = 0; i < n; i ++)  cin >> a[i];
		for(int i = 0; i < c; i ++)  cin >> b[i];
		for(int i = 1; i <= m; i ++){
			cin >> u >> v >> w;
			e[++ k] = {v, w, h[u]}, h[u] = k;
			e[++ k] = {u, w, h[v]}, h[v] = k;
		}
		dijkstra(0);
		int ans = a[0] + b[0];
		for(int i = 1; i < n; i ++){
			// cerr << i << ' ' << d[i] << '\n';
			if(d[i] * 2 + a[i] + b[0] < ans)  ans = d[i] * 2 + a[i] + b[0];
		}
		cout << ans;
	}
};

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> c;
	if(c == 1){
		bf::main();
	}
	if(n == c)  zip::main();

	return 0;
}
