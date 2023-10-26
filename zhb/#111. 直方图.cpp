#include<bits/stdc++.h>
using namespace std;
int n,a[10002],maxn;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	int t;
	for(int i=1;i<=n;i++){
		cin >> t;
		a[t]++;
		maxn = max(maxn,t);
	}
	for(int i=0;i<=maxn;i++){
		cout << a[i] << '\n';
	}
	
	return 0;
}
