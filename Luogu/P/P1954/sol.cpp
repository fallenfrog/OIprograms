#include<bits/stdc++.h>
#define PII pair<int, int>
#define d first
#define idx second
#define mp make_pair
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 2e3 + 2;
const int M = 1e4 + 2;

int n, m, h[N], k[N], u, v, cnt, rin[N], in[N], ans[N], tot;
struct edge{
	int v, nxt;
}e[M];
priority_queue<PII, vector<PII>, greater<PII>> q;

int solve(int x){
	tot = 0;
	while(!q.empty())	q.pop();
	for(int i = 1; i <= n; i ++)	in[i] = rin[i];
	for(int i = 1; i <= n; i ++)
		if(!in[i] && i != x)
			q.push(mp(n - k[i], i));
			
	while(!q.empty()){
		PII t = q.top();	q.pop();
		if(n - tot > k[t.idx])	return n - tot;
		tot ++;
		for(int i = h[t.idx]; i; i = e[i].nxt){
			int v = e[i].v;
			in[v] --;
			if(!in[v] && v != x){
				q.push(mp(n - k[v], v));
			}
		}
	}
	return n - tot;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)	cin >> k[i];
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		e[++ cnt] = {u, h[v]}, h[v] = cnt, in[u] ++, rin[u] ++;
	}
	
	for(int i = 1; i <= n; i ++)
		if(!in[i])
			q.push(mp(n - k[i], i));
			
	while(!q.empty()){
		PII t = q.top(); q.pop();
		ans[++ tot] = t.idx;
		for(int i = h[t.idx]; i; i = e[i].nxt){
			int v = e[i].v;
			in[v] --;
			if(!in[v])	q.push(mp(n - k[v], v));
		}
	}
	for(int i = tot; i > 0; i --)	cout << ans[i] << ' ';
	cout << '\n';
	for(int i = 1; i <= n; i ++)	cout << solve(i) << ' ';

	return 0;
}
