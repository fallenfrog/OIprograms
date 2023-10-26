#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "string";
const int N = 3e4 + 2;
const int L = 3e5 + 2;

int n, cnt, comp[30][30]; // comp[a][b] (1 : a > b, -1 : a < b, 0 : a ? b)
string t, ans[N];
unordered_map <string, int> idx;

struct Trie{
	int a[L][30], tot;
	bool isword[L];
	void insert(string s){
		int tmp = 0;
		for(auto t : s){
			if(isword[tmp])  return ;
			int tt = t - 96;
			if(!a[tmp][tt])  a[tmp][tt] = ++ tot;
			tmp = a[tmp][tt];
		}
		isword[tmp] = 1;
	}
	void work(int now, string p){
		if(isword[now]){
			ans[++ cnt] = p;
			return ;
		}
		int tmp = 0, t[30];
		for(int i = 1; i <= 26; i ++){
			if(a[now][i] && comp[tmp][i] == 1)
				tmp = i;
		}
		for(int i = 1; i <= 26; i ++){
			if(a[now][i] && (i == tmp || comp[tmp][i] == 0)){
				for(int j = 1; j <= 26; j ++){
					t[j] = comp[i][j];
					if(a[now][j] && i != j && comp[i][j] == 0)  comp[i][j] = -1, comp[j][i] = 1;
				}
				work(a[now][i], p + (char)(i + 96));
				for(int j = 1; j <= 26; j ++)  comp[i][j] = t[j], comp[j][i] = -t[j];
			}
		}
	}
}trie;

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= 26; i ++)  comp[0][i] = 1, comp[i][0] = -1;
	for(int i = 1; i <= n; i ++){
		cin >> t;
		idx[t] = i;
		trie.insert(t);
	}
	trie.work(0, "");
	cout << cnt << '\n';
	sort(ans + 1, ans + cnt + 1, [](string a, string b){return idx[a] < idx[b];});
	for(int i = 1; i <= cnt; i ++)  cout << ans[i] << '\n';

	return 0;
}
/*
input:
4
omm
moo
mom
ommnom
*/
