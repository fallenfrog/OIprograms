#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "yume";
const int N = 1e5 + 2;
const int M = 2e5 + 2;

int n, m, k, u, v, l, r, clr[N], tl, tr;
bool fl, fr;
struct edge{int v, l, r;};
vector <edge> e[N];

namespace bf{
	bool dfs(int x, int c, int tim){
		clr[x] = c;
		for(auto eg : e[x]){
			int v = eg.v, l = eg.l, r = eg.r;
			if(tim < l || tim >= r)  continue;
			if(clr[v]){
				if(!(clr[x] ^ clr[v]))  return 0;
				continue;
			}
			if(!dfs(v, 3 - c, tim))  return 0;
		}
		return 1;
	}
	
	void solve(int tim){
		for(int i = 1; i <= n; i ++)  clr[i] = 0;
		for(int i = 1; i <= n; i ++){
			if(!clr[i] && !dfs(i, 1, tim)){
				cout << "No\n";
				return ;
			}
		}
		cout << "Yes\n";
	}
	
	void main(){
		for(int i = 0; i < k; i ++)
			solve(i);
	}
}

namespace bf2{
	bool flag = 0;
	void main(){
		for(int i = 0; i < tl; i ++)  cout << "Yes\n";
		for(int i = 1; i <= n; i ++){
			if(!clr[i] && !bf::dfs(i, 1, tl)){
				flag = 1;
				break;
			}
		}
		for(int i = tl; i < tr; i ++){
			if(flag)  cout << "No\n";
			else  cout << "Yes\n";
		}
		for(int i = tr; i < k; i ++)  cout << "Yes\n";
	}
}

namespace bf3{
	bool solve(int tim){
		for(int i = 1; i <= n; i ++)  clr[i] = 0;
		for(int i = 1; i <= n; i ++){
			if(!clr[i] && !bf::dfs(i, 1, tim))  return 0;
		}
		return 1;
	}
	
	void main(){
		for(int i = 0; i < tl; i ++)  cout << "Yes\n";
		for(int i = tl; i < k; i ++){
			if(solve(i)){
				for(; i < k; i ++)  cout << "Yes\n";
				return ;
			}
			cout << "No\n";
		}
	}
}

namespace bf4{
	bool solve(int tim){
		for(int i = 1; i <= n; i ++)  clr[i] = 0;
		for(int i = 1; i <= n; i ++){
			if(!clr[i] && !bf::dfs(i, 1, tim))  return 0;
		}
		return 1;
	}
	
	void main(){
		for(int i = 0; i < tr; i ++){
			if(!solve(i)){
				for(; i < tr; i ++)  cout << "No\n";
				break;
			}
			cout << "Yes\n";
		}
		for(int i = tr; i < k; i ++)  cout << "Yes\n";
	}
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++){
		cin >> u >> v >> l >> r;
		if(tl != l)  fl = 1;
		if(tr != r)  fr = 1;
		e[u].push_back(edge{v, l, r});
		e[v].push_back(edge{u, l, r});
		tl = l, tr = r;
	}
	if(!fl && !fr)  bf2::main();
	else if(!fl)  bf3::main();
	else if(!fr)  bf4::main();
	else  bf::main();

	return 0;
}

