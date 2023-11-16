#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "perm";
const int N = 3e5 + 2;

int n, a[N], q[N], pos[N], pp[N], ans[N];

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++)  cin >> q[i];
	int tmp = 0;
	for(int i = 1; i <= n; i ++){
		if(i == q[n]){
			tmp = a[i];
			continue;
		}
		if(a[i] > tmp)  pp[i] = a[i];
		else  pp[i] = tmp, tmp = a[i];
	}
	ans[n] = tmp;
	for(int i = n - 1; i; i --){
		tmp = pp[q[i]];
		pp[q[i]] = 0;
		for(int j = q[i] + 1; j <= n; j ++){
			if(pp[j] && pp[j] < tmp){
				swap(tmp, pp[j]);
			}
		}
		ans[i] = max(tmp, ans[i + 1]);
	}
	for(int i = 1; i < n; i ++)  cout << ans[i] << ' ';
	cout << ans[n];

	return 0;
}
/*
6
2 3 6 1 5 4
5 2 1 4 6 3
*/
