#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;
const int M = 2e5 + 2;
const int N1 = 1e3 + 2;
const int M1 = 2e3 + 2;

int n, p, tim, m[N], g[N], u, v, dist[N];
struct node{
	int line, ord, idx;
	bool operator < (const node& other) const{
		return line < other.line || (line == other.line && ord < other.ord);
	}
};
set<int> line[N1];
set<node> e[N1];

#define PII pair<int, node>
#define dist first
#define id second
int d[N];
bool vis[N];
void dijkstra(int s){
	memset(d, 0x3f, sizeof(d));
	priority_queue<PII, vector<PII>, greater<PII> > q;
	for(auto t : e[0]){
		d[t.idx] = t.ord * g[t.line];
		q.push({t.ord * g[t.line], t});
	}
	while(!q.empty()){
		PII t = q.top();	q.pop();
		if(vis[t.id.idx])	continue;
		vis[t.id.idx] = 1;
		for(auto tt : e[t.id.idx]){
			if(tt.line == t.id.line){
				if(d[tt.idx] > d[t.id.idx] + 1)
					d[tt.idx] = d[t.id.idx] + 1;
			}else{
				int td = ((d[t.id.idx] + tim - 1) / g[tt.line] + 1) * g[tt.line] + 1;
				if(d[tt.idx] > td)  d[tt.idx] = td;
			}
			cerr << tt.idx << ' ' << d[tt.idx] << '\n';
		}
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> p >> tim;
	for(int i = 1; i <= p; i ++){
		cin >> m[i] >> g[i] >> u;
		int temp = u;  line[i].insert(u);
		if(temp == 1)
			e[0].insert({0, 0, temp});
		for(int j = 1; j <= m[i]; j ++){
			cin >> v;  line[i].insert(v);
			e[u].insert({i, j, v});
			if(v == 1)
				e[0].insert({i, j, v});
			u = v;
		}
		e[u].insert({i, 0, temp});
	}
	dijkstra(1);
	cout << d[n];

	return 0;
}
/*
5 3 1
3 3
4 2 3 5
2 1
2 1 4
2 4
4 1 2
*/
