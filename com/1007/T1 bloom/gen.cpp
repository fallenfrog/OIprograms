#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 3e7 + 2;

int n, a[N], s1, s2, s3;

void Gen(int n, unsigned s1, unsigned s2, unsigned s3){
	for(int i = 1; i <= n; i ++){
		s1 ^= s3;
		s3 += 3055373123u;
		a[i] = (1 << ((s1 >> s2) & 1));
		s2 = (s2 ^ s3) & 31;
		s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
	}
}

int main(){
	//FileIO("bloom");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> s1 >> s2 >> s3;
	Gen(n, s1, s2, s3);
	for(int i = 1; i <= n; i ++)	cout << a[i] << ' ';

	return 0;
}

