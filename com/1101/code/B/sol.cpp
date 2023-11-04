#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "chr";
const int N = 1e5 + 2;
const int K = 22;

int T, n, a[N], mxn, mnn, l, r, L, R, mxt, mnt, mxl, mnl, d, ans;
int lg[N], mx[N][K], mn[N][K];
int minn(int x, int y){return a[x] < a[y] ? x : y;}
int maxn(int x, int y){return a[x] > a[y] ? x : y;}
bool flag;

void init(){
	for(int i = 1; i <= n; i ++)  mx[i][0] = i, mn[i][0] = i;
	for(int i = 1, len = 2; len <= n; i ++, len <<= 1){
		for(int j = 1; j + len - 1 <= n; j ++){
			mx[j][i] = maxn(mx[j][i - 1], mx[j + (len >> 1)][i - 1]);
			mn[j][i] = minn(mn[j][i - 1], mn[j + (len >> 1)][i - 1]);
		}
	}
}

int query(int l, int r, int k){
	if(l > r)
		if(k)  return n + 1;
		else   return 0;
	int len = lg[r - l + 1];
	if(k)  return minn(mn[l][len], mn[r - (1 << len) + 1][len]);
	else   return maxn(mx[l][len], mx[r - (1 << len) + 1][len]);
}

bool check(int x){
	int l = n, r = 0, d = 0;
	for(int i = 1; i <= n; i ++){
		if(a[i] + x < mxn)
			l = min(l, i),
			r = max(r, i),
			d = max(d, mxn - a[i] - x);
	}
	int tmax = max(a[query(l, r, 0)] + d, a[maxn(query(1, l - 1, 0), query(r + 1, n, 0))]);
	int tmin = min(a[query(l, r, 1)] + d, a[minn(query(1, l - 1, 1), query(r + 1, n, 1))]);
	return tmax - tmin <= x;
}

void solve(){
	cin >> n;  mxn = mxt = -1, mnn = mnt = ans = a[n + 1] = 2e9;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mxn = max(mxn, a[i]);
		mnn = min(mnn, a[i]);
	}
	init();
	l = 0, r = mxn - mnn;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r << '\n';
}

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	lg[1] = 0;
	for(int i = 2; i < N; i ++)  lg[i] = lg[i >> 1] + 1;
	cin >> T;
	while(T --)  solve();

	return 0;
}

