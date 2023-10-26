#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "poly";

int T, a, b, c, res;

int qpow(int b, int p){
	int res = 1;
	for(; p; p >>= 1, b = b * b)  if(p & 1)  res = res * b;
	return res;
}

void work(int p, int m1, int m2){
	if(m1 == m2 && m2 == 0){
		res ++;
		return ;
	}
	int t1 = qpow(a, p), t2 = qpow(b, p);
	for(int i = 1; i * t1 <= m1 && i * t2 <= m2; i ++){
		work(p + 1, m1 - i * t1, m2 - i * t2);
	}
}

int main(){
	FileIO(name + "3");
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> T;
	while(T --){
		cin >> a >> b >> c;  res = 0;
		if(a == b && b == c){
			if(a == 0 || a == 1){
				cout << "-1\n";
			}else{
				cout << "2\n";
			}
		}else{
			if(b == c){
				cout << "1\n";
			}else{
				work(0, b, c);
				cout << res << '\n';
			}
		}
	}

	return 0;
}

