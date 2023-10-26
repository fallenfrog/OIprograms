#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int T, n, m, h[N], in[N], k, u, v, tot, ans[N];
struct edge {
	int v, nxt;
}e[N];

void solve(){
	cin >> n >> m;	k = tot = 0;
	for(int i = 1; i <= n; i ++)	h[i] = in[i] = ans[i] = 0;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v;
		if(u == v){
			cout << "Impossible!\n";
			return ;
		}
		e[++ k] = {u, h[v]}, h[v] = k, in[u] ++;
	}
	
	priority_queue<int, vector<int>, less<int> > q;
	for(int i = 1; i <= n; i ++)	if(!in[i])	q.push(i);
	while(!q.empty()){
		int t = q.top();	q.pop();
		ans[++ tot] = t;
		for(int i = h[t]; i; i = e[i].nxt){
			int v = e[i].v;
			in[v] --;
			if(!in[v])	q.push(v);
		}
	}
	
	if(tot < n){
		cout << "Impossible!\n";
		return ;
	}
	for(int i = n; i > 0; i --)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	cin >> T;
	while(T --)
	solve();
	
	return 0;
}