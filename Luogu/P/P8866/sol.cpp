#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P8866";
const int N = 302;

int T, n, m, k, t, s[N], tot, cnt, idx[N];
set <int> st, mr;
unordered_map <int, int> ma;
// struct op{
	// int k, a, b;
// }ans[]

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> m >> k;   tot = 0;
		for(int i = 1; i <= n; i ++)
			st.insert(i);
		for(int i = 1; i <= m; i ++){
			cin >> t;
			if(!ma[t]){
				if(st.size()){
					ma[t] = *st.begin();
					st.erase(st.begin());
				}else{
					ma[t] = ++ tot;
				}
			}else{
				if(ma[t] <= n){
					st.insert(ma[t]);
					ma[t] = 0;
				}else{
				}
			}
		}
		st.clear();
	}
	
	return 0;
}
