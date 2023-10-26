#include<bits/stdc++.h>
using namespace std;
int n,d[200004];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int a,b;
		cin >> a >> b;
		d[a]++;d[b]--;
	}
	int ans = 0,t = 0;;
	for(int i=1;i<=10000;i++){
		t += d[i];
		ans = max(ans,t);
	}
	cout << ans;
	
	return 0;
} 
