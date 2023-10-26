#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=-1e9;

signed main(){
	cin >> n >> m;
	if(n==0){
		cout << -m*m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l1 = m%(i+1);
		int l2 = i+1-l1;
		int s0 = (n-i+1)*(n-i+1)+(i-1);
		int s2 = (m/(i+1)+1)*(m/(i+1)+1)*l1+(m/(i+1))*(m/(i+1))*l2;
		ans = max(ans,s0-s2);
	}
	cout << ans;
	
	return 0;
}
