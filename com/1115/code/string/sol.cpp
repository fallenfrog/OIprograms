#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "string";
const int N = 1e5 + 2;

int n, q, x, y, hal, tot;
int idx[300];
struct node{
	char c;
	int n;
}cnt[300];
string s;

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> s >> q;  n = s.size();
	hal = n >> 1;
	for(auto t : s){
		if(!idx[t])
			idx[t] = ++ tot;
		cnt[idx[t]].n ++;
	}
	sort(cnt + 1, cnt + tot + 1, [](node x, node y){return x.n > y.n;});
	for(int i = 1; i <= tot; i ++){
		idx[cnt[i].c] = i;
	}
	for(int i = 1; i <= tot; i ++){
		
	}

	return 0;
}

