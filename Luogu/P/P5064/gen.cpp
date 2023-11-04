#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 20;
const int A = 100;

int n, m, op;

int main(){
//	FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	srand(time(0));
	n = (((long long)rand() << 15) + rand()) % N + 1;
	m = (((long long)rand() << 15) + rand()) % 10 + 1;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i ++)  cout << (((long long)rand() << 15) + rand()) % A + 1 << ' ';  cout << '\n';
	for(int i = 1; i <= m; i ++){
		cout << (op = rand() % 3 + 1) << ' ';
		if(op == 2)  cout << rand() % i << '\n';
		else  cout << (((long long)rand() << 15) + rand()) % n + 1 << ' ' << (((long long)rand() << 15) + rand()) % n + 1 << '\n';
	}

	return 0;
}
