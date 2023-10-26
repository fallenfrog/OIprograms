#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 2;

int n, t;
ll ans;
string s;
unordered_map<string, int> idx;

#define lowbit(x) ((x) &- (x))
int d[N];

void add(int x, int k){
	while(x <= n){
		d[x] += k,
		x += lowbit(x);
	}
}

ll query(int x){
	ll res = 0;
	while(x){
		res += d[x];
		x -= lowbit(x);
	}
	return res;
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> s;
		idx[s] = i;
	}
	for(int i = 1; i <= n; i ++){
		cin >> s;
		t = idx[s];
		ans += i - query(t) - 1;
		add(t, 1);
	}
	cout << ans;

	return 0;
}
