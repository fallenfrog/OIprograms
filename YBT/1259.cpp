#include<bits/stdc++.h>
using namespace std;
int n,a[203],dp[203];
vector<int> q[203];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[i] = 1;
		q[i].push_back(a[i]);
	}
	int ans = 0;
	vector<int>	aq;
	for(int i=n-1;i>0;i--){
		for(int j=i+1;j<=n;j++){
			if(a[j]>=a[i] && dp[j]>=dp[i]){
				dp[i] = dp[j]+1;
				q[i] = q[j];
				q[i].push_back(a[i]);
			}
		}
		if(dp[i]>ans){
			ans = dp[i];
			aq = q[i];
		}
	}
	cout << "max=" << ans << '\n';
	for(int i=aq.size()-1;i>=0;i--){
		cout << aq[i] << ' ';
	}
	
	return 0;
}
