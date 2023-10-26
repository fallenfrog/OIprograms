#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 2;

struct node{
	string s;
	int idx;
	bool operator < (const node& other) const{
		return idx < other.idx;
	}
};
int n, temp;
char c;
string t, m[N];
set<node> mem, act; 
set<int> ans;

bool dfs(string s){
	bool res = 0;
	for(auto t : act){
		string tt = t.s;
		if(tt == s)	return 1;
		if(s.substr(0, tt.size()) == tt){
			cerr << s.substr(0, tt.size()) << '\n';
			res |= dfs(s.substr(tt.size() - 1, s.size() - tt.size()));
			if(res)	return 1;
		}
	}
	return res;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		ans.clear();
		cin >> c >> t;
		t = (t + t).substr(temp, t.size());
		cerr << "orgin " << t << '\n';
		if(c == '?')
			mem.insert({(m[mem.size() + 1] = t), mem.size() + 1});
		else
			act.insert({t, i});
		for(auto t : mem){
			if(dfs(t.s))
				ans.insert(t.idx);
		}
		cout << (temp = ans.size()) << ' ';
		for(auto t : ans){
			cout << t << ' ';
			mem.erase({m[t], t});
		}
		cout << '\n';
	}

	return 0;
}
/*
5
? abcabd
+ abc
? abcabc
? dabdab
+ abd
*/
