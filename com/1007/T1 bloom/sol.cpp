#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3e7 + 2;

int n, a[N], ans;
int q[N], l, len;
unsigned s1, s2, s3;

inline void Gen(int n, unsigned s1, unsigned s2, unsigned s3){
	for(int i = 1; i <= n; i ++){
		s1 ^= s3;
		s3 += 3055373123u;
		a[i] = (1 << ((s1 >> s2) & 1));
		s2 = (s2 ^ s3) & 31;
		s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
	}
}

inline void solve(){
	l = 1, len = n;
	while(len > 1){
		ans ++;
		if(a[l] == 1 || (a[l] == 2 && a[l + 1] == 2)){
			a[l + 1] = a[l] - 1, a[l + 2] -= 1;
			l ++, len --;
			if(!a[l]){
				l ++, len --;
				if(!a[l]){
					l ++, len --;
				}
			}
			else if(!a[l + 1])	a[l + 1] = a[l], l ++, len --;
		}else{
			a[++ l] --, len --;
			if(!a[l])	l ++, len --;
		}
		if(l > n){
			cout << ans;
//			cerr << l << ' ' << len << '\n';
			return ;
		}
//		cerr << l << ' ' << len << '\n';
	}
//	cerr << l << ' ' << len << '\n';
	cout << ans + len;
}

int main(){
	FileIO("bloom");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> s1 >> s2 >> s3;
	Gen(n, s1, s2, s3);
	solve();

	return 0;
}
/*
Input 1:
5 114514 3 1919810
Output 1:
2

Input 2:
114514 166032413 6 102134106
Output 2:
49469
*/

