#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".ans").c_str(), "w", stdout);
}

const int N = 5e5 + 2;

int n, m, a[N << 1], pos[N];

int dfs(int x, int l, int r){
	if(x > n)	return 0;
	int res = 1e9, tp, ld, rd;
	tp = pos[x] - l + 1;
	if(tp <= 0)	tp += n;
	if(tp <= m)	dfs(x + 1, l, r);
	ld = abs(tp - m), rd = abs(n - tp + 1);
//	if(ld < rd){
//		l += ld, r += ld;
//		if(r >= n + n)	l -= n, r -= n;
//		res = min(ld + dfs(x + 1, l, r), res);
////		l -= ld, r -= ld;
//	}
//	else if(ld > rd){
//		l -= rd, r -= rd;
//		if(l <= 0)	l += n, r += n;
//		res = min(res, rd + dfs(x + 1, l, r));
//	}
//	else{
		l += ld, r += ld;
		if(r >= n + n)	l -= n, r -= n;
		res = min(ld + dfs(x + 1, l, r), res);
		l -= ld + rd, r -= ld + rd;
		if(l <= 0)	l += n, r += n;
		res = min(res, rd + dfs(x + 1, l, r));
//	}
	return res;
}

void solve1(){
	cout << dfs(1, 1, n);
}

int main(){
	FileIO("ex_data2");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	
	solve1();

	return 0;
}
/*
5 2
3 5 1 4 2

3 2
2 3 1
*/
