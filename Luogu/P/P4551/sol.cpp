#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;
const int L = 31;

int n, h[N], k, u, v, w, d[N], ans;
struct edge{
	int v, w, nxt;
}e[N << 1];

struct trie01{
	int a[L * N][2], cnt;
	bool isn[L * N];
	void insert(int x){
		int tmp = 0;
		for(int i = 1; i <= L; i ++){
			if(x & (1 << L - i)){
				if(!a[tmp][1])  a[tmp][1] = ++ cnt;
				tmp = a[tmp][1];
			}else{
				if(!a[tmp][0])  a[tmp][0] = ++ cnt;
				tmp = a[tmp][0];
			}
		}
		isn[tmp] = 1;
	}
	int query(int x){
		int res = 0, tmp = 0;
		for(int i = 1; i <= L; i ++){
			if((x & (1 << L - i)) && a[tmp][0]){
				tmp = a[tmp][0];
				res += (1 << L - i);
			}
			else if(!(x & (1 << L - i)) && a[tmp][1]){
				tmp = a[tmp][1];
				res += (1 << L - i);
			}
			else if(a[tmp][0])  tmp = a[tmp][0];
			else if(a[tmp][1])  tmp = a[tmp][1];
			else break;
		}
		return res;
	}
}trie;

void dfs(int x, int fa){
	for(int i = h[x]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == fa)  continue;
		d[v] = d[x] ^ e[i].w;
		trie.insert(d[v]);
		dfs(v, x);
	}
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i < n; i ++){
		cin >> u >> v >> w;
		e[++ k] = {v, w, h[u]}, h[u] = k;
		e[++ k] = {u, w, h[v]}, h[v] = k;
	}
	dfs(1, 0);
	for(int i = 1; i < n; i ++){
		ans = max(ans, trie.query(d[i]));
	}
	cout << ans;

	return 0;
}
