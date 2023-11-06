#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "ensata";
const int N = 2e3 + 2;

int a, b, n, ta, tb; 

int main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> a >> b;
	if(a == b + 3 || a < b + 2){
		cout << "0\n";
		return 0;
	}
	if(a == b + 2){
		cout << a + b << '\n';
		for(int i = 1; i < b; i ++){
			cout << i << ' ' << i + 1 << '\n';
			cout << i + b << ' ' << i << '\n';
		}
		cout << b + b << ' ' << 1 << '\n';
		cout << b + b + 1 << ' ' << b << '\n';
		cout << b + b + 2 << ' ' << b << '\n';
		return 0;
	}
	cout << a + b + 1 << '\n';
	for(int i = 1; i <= b; i ++){
		cout << i << ' ' << i + 1 << '\n';
		cout << i + b << ' ' << i << '\n';
	}
	cout << b + b + 1 << ' ' << b + 1 << '\n';
	cout << b + b + 2 << ' ' << 1 << '\n';
	cout << b + b + 3 << ' ' << b + 1 << '\n';
	for(int i = b + b + 4; i <= a + b; i ++){
		cout << i << ' ' << 1 << '\n';
	}

	return 0;
}

