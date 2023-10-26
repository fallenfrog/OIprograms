#include<bits/stdc++.h>
using namespace std;
int n,l,r;
priority_queue<int> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> l >> r;
	for(int i=1;i<=n;i++){
		int t;	cin >> t;
		q.push(t);
	}
	int ans;
	for(int i=1;i<=l;i++){
		ans += q.top();
		q.pop();
	}
	printf("%.3lf",ans*1.0/l);
	
	return 0;
}
