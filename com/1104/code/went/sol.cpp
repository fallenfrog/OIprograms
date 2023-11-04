#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "went";
const int N = 1e6 + 2;

int n, fa[N], cnt[N];
string s;
int find(int x){return (x == fa[x] ? x : (fa[x] = find(fa[x])));}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> s;  s = "#" + s;
	for(int i = 1; i <= n; i ++){
		fa[i] = i;
		int last = i;
		while(last){
			if(s[last - 1] != '#' && s[last - 1] != s[i]){
				cnt[i] = cnt[i - 1];
				fa[i] = last - 1;
				break;
			}
			last = find(last - 1);
		}
		if(!last)  cnt[i] = cnt[i - 1] + 1;
	}
	cout << cnt[n];

	return 0;
}

