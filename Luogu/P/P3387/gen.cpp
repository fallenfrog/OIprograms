#include<bits/stdc++.h>
using namespace std;

const int N = 1e2;
const int M = 1e3;
const int A = 1e2 + 1;

int n, m;

int main(){
	srand(time(0));
	n = rand() % N + 1, m = rand() % M + 1;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i ++)	cout << rand() % A << ' ';
	cout << '\n';
	for(int i = 1; i <= m; i ++){
		int u = rand() % n + 1, v = rand() % n + 1;
		if(u == v){
			i --;
			continue;
		}
		cout << u << ' ' << v << '\n';
	}
	
	return 0;
}
