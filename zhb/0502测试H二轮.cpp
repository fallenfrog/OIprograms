#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,sum[300005],t,ans=-INF;
deque<int> q;

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> t;
		sum[i] = sum[i-1]+t;
	}
	q.push_back(0);
	for(int i=1;i<=n;i++){
		if(!q.empty() && i-m>q.front())	q.pop_front();
		t = sum[i]-sum[q.front()];
		if(t>ans)	ans = t;
		while(!q.empty() && sum[q.back()]>=sum[i])	q.pop_back();
		q.push_back(i);
	}
	cout << ans;
	
	return 0;
}
