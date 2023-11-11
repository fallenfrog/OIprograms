#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "xor";
const int N = 1e5 + 2;

int n, m, t;

namespace trie{
	int son[N * 20][2];
	int siz[N * 20];
	int cnt[N * 20];
	int tot, ans;

	void insert(int x){
		int tmp = 0;
		for(int p = 32; p; p --){
			int k = (x >> p - 1) & 1;
			if(!son[tmp][k])
				son[tmp][k] = ++ tot;
			siz[son[tmp][k]] ++;
			if(!k)  cnt[tmp] += siz[son[tmp][1]];
			tmp = son[tmp][k];
		}
	}

	int query(int x, int p = 32, int pos = 0){
		if(!p)  return 0;
		int k = (x >> p - 1) & 1,
			res = 0;
		if(!k)  res += cnt[pos];
		else  res += siz[son[pos][1]] * siz[son[pos][0]] - cnt[pos];
		if(son[pos][1])  res += query(x, p - 1, son[pos][1]);
		if(son[pos][0])  res += query(x, p - 1, son[pos][0]);
		return res;
	}
}

signed main(){
#ifndef ONLINE_JUDGE
	FileIO(name);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> t;
		trie::insert(t);
	}
	for(int i = 1; i <= m; i ++){
		cin >> t;
		cout << trie::query(t) << '\n';
	}
	
	return 0;
}