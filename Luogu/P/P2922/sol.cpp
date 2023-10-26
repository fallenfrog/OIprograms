#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 5e4 + 2;
const int M = 5e5 + 2;

int n, m, k, p;
string t;
struct trie01{
	int a[M][2], siz[M], tot = 1;
	int isn[M];
	void insert(string x, int pos, int len){
		if(len == x.size()){
			siz[pos] ++, isn[pos] ++;
			return ;
		}
		int tmp = x[len] - '0';
		if(!a[pos][tmp])  a[pos][tmp] = ++ tot;
		insert(x, a[pos][tmp], len + 1);
		siz[pos] = siz[a[pos][0]] + siz[a[pos][1]] + isn[pos];
		// cerr << pos << ' ' << siz[pos] << ' ' << a[pos][0] << ' ' << siz[a[pos][0]] << ' ' << a[pos][1] << ' ' << siz[a[pos][1]] << '\n';
	}
	int query(string x, int len){
		int res = 0, tmp = 1;
		for(int i = 0; i < len; i ++){
			res += isn[tmp];
			int pos = a[tmp][x[i] - '0'];
			// cerr << pos << ' ';
			if(!pos){
				// cerr << '\n';
				return res;
			}
			tmp = pos;	
		}
		res += siz[tmp];
		// cerr << "size=" << siz[tmp] << '\n';
		return res;
	}
}trie;

signed main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> k;  t = "";
		for(int j = 0; j < k; j ++){
			cin >> p;
			t.push_back(p + '0');
		}
		trie.insert(t, 1, 0);
	}
	for(int i = 1; i <= m; i ++){
		cin >> k;  t = "";
		for(int j = 0; j < k; j ++){
			cin >> p;
			t.push_back(p + '0');
		}
		cout << trie.query(t, k) << '\n';
	}

	return 0;
}
