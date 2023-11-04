#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "soldier";
const int M = 52;

int n, m, k, t, ans;
struct node{
	int tot, num[M], sum[M];
	bool ps[M];
};

namespace bf{
	const int N = 7502;
	const int M = 52;
	
	node nd[N];
	
	void main(){
		for(int i = 1; i <= n; i ++){
			cin >> nd[i].tot;
			for(int j = 1; j <= nd[i].tot; j ++){
				cin >> nd[i].num[j];
				nd[i].ps[nd[i].num[j]] = 1;
				for(int k = nd[i].num[j]; k <= m; k ++)  nd[i].sum[k] ++;
			}
			for(int j = 1; j < i; j ++){
				bool tmp = 1;
				for(int k = 1; k <= nd[i].tot; k ++){
					if(nd[j].sum[nd[i].num[k]] > nd[j].sum[nd[i].num[k - 1]])  tmp ^= 1;
				}
				if(!tmp)  ans ++;
			}
		}
		cout << ans << '\n';
	}
}

signed main(){
	FileIO("data");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	bf::main(); 

	return 0;
}
