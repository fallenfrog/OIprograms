#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "CF1822D";
const int N = 1e5 + 2;

int T, n;

void solve1(){
	cin >> n;
	if(n > 1 && (n & 1)){
		cout << "-1\n";
		return ;
	}
	cout << n << ' ';
	for(int i = 2; i <= n; i += 2){
		cout << n + 1 - i << ' ';
		if(i < n)  cout << i << ' ';
	}
	cout << '\n';
}

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T --)  solve1();

	return 0;
}
