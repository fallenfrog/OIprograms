#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "songfen";
const int N = 5e3 + 2;

int n, k, A, B, c[N], ans, cnt, r[N], tmp[N];

int calc(){
	for(int i = 1; i <= n; i ++)
		tmp[i] = min(tmp[max(0ll, i - k)] + A, tmp[i - 1] + c[i]);
	return tmp[n];
}

#define down 0.996
void SA(){
	double st = 3000;  cnt = 0;
	for(int i = 1; i <= n; i ++)  c[i] = r[i];
	while(st > 1e-15){
		int tx = rand() % (n - 1) + 1;
		swap(c[tx], c[tx + 1]), cnt ++;
		int tv = calc() + cnt * B;
		if(tv < ans)  ans = tv;
		else if(exp((ans - tv) / st) * rand() > RAND_MAX)  swap(c[tx], c[tx + 1]), cnt --;
		st *= down;
	}
}

signed main(){
	FileIO(name);
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	srand(time(0));
	cin >> n >> k >> A >> B;
	for(int i = 1; i <= n; i ++)  cin >> r[i];
	for(int i = 1; i <= n; i ++)  c[i] = r[i];
	ans = calc();
	for(int i = 1; i <= 10; i ++)  SA();
	cout << ans;

	return 0;
}

