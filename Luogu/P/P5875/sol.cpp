#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P5875";
const int N = 1e5 + 2;

int n, a[N], u[N], op[N];

// code
int findSample(int n, int a[], int u[], int op[]){
	int ans = 0;
	for(int i = n - 1; i; i --){
		switch(op[i]){
			case 0:  ans += a[i], a[u[i]] = max(0, a[u[i]] - a[i]);  break;
			case 1:  a[u[i]] += a[i];  break;
			case 2:  a[u[i]] = max(a[u[i]], a[i]);  break;
		}
		// cerr << i << ' ' << a[i] << '\n';
	}
	// cerr << "0 " << a[0];
	return ans + a[0];
}
// end

int main(){
	//FileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i ++)  cin >> a[i];
	for(int i = 1; i < n; i ++)  cin >> u[i] >> op[i];
	cout << findSample(n, a, u, op);

	return 0;
}
