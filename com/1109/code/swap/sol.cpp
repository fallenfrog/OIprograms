#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "swap";
const int N = 1e5 + 2;

int T, n, k, a[N], b[N], ans;

namespace bf{
	void solve(){
		for(int i = 1; i <= n; i ++)  cin >> a[i];
		for(int i = 1; i <= n; i ++)  cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		ans = 0;
		for(int i = 1; i <= n; i ++)  ans += abs(a[i] - b[n - i + 1]);
		cout << ans << '\n';
	}
}

namespace bf2{
	int rnk[N], cnt[N], tmp;
	struct node{
		int a, b;
	}nd[N];
	
	void solve(){
		for(int i = 1; i <= n; i ++){cin >> nd[i].a;  a[i] = nd[i].a;}
		for(int i = 1; i <= n; i ++){cin >> nd[i].b;  b[i] = nd[i].b;}
		sort(nd + 1, nd + n + 1, [](node x, node y){return x.b < y.b;});
		sort(a + 1, a + n + 1);  ans = 0;
		for(int i = 1; i <= n; i ++){
			int t = lower_bound(a + 1, a + n + 1, nd[i].a) - a;
			t += cnt[t] ++;
			rnk[i] = t;
			ans += abs(nd[i].a - nd[i].b);
		}
		int ai = 1, am = n, bi = 1, bm = n;
		while(k){
			if(nd[rnk[ai]].a > nd[bm].b || nd[rnk[am]].a < nd[bi].b)  break;
			int t1 = (nd[bm].b - nd[rnk[ai]].a) << 1,
				t2 = (nd[rnk[am]].a - nd[bi].b) << 1;
			if(k >= 2){
				ans += t1 + t2;
				bm --, am --, bi ++, ai ++;
				k -= 2;
			}else{
				ans += max(t1, t2);
				k --;
			}
		}
		cout << ans << '\n';
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> n >> k;
		if(n == 2){
			int a1, a2, b1, b2;
			cin >> a1 >> a2 >> b1 >> b2;
			if(k & 1)  cout << abs(a1 - b2) + abs(a2 - b1) << '\n';
			else  cout << abs(a1 - b1) + abs(a2 - b2) << '\n';
			continue;
		}
		if(k >= n - 1){
			bf::solve();
		}else{
			bf2::solve();
		}
	}

	return 0;
}

