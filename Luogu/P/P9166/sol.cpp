#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P9166";
const int N = 2e5 + 2;

int n, m, s, f[N], ise[N], l, r, u, v;
int find(int x){return (x == f[x] ? x : (f[x] = find(f[x])));}
struct node{
	int l, r;
}nd[N];

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++)  f[i] = i;
	for(int i = 1; i <= m; i ++){
		cin >> nd[i].l >> nd[i].r;
		if(nd[i].l < s)  ise[nd[i].l] = 1;
		if(nd[i].r > s)  ise[nd[i].r] = 1;
	}
	sort(nd + 1, nd + m + 1, [](node x, node y){return x.l == y.l ? x.r < y.r : x.l < y.l;});
	l = r = 0;
	for(int i = 1; i <= n; i ++){
		if(r > s && nd[i].l > r)  break;
		if(nd[i].l > r){
			l = nd[i].l, r = nd[i].r;
		}else{
			r = max(r, nd[i].r);
		}
	}
	for(int i = l; i <= r; i ++)
		if(ise[i])  cout << i << ' ';

	return 0;
}
