#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,k,a[1000006],d[1000006],ans=INF;
deque<int> q;

int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	a[0] = INF;
	for(int i=1;i<=n;i++)
		d[i] = a[i]-a[i-1];
	for(int i=1;i<=n;i++){
		while(!q.empty() && i-q.front()+1>=n-k)	q.pop_front();
		while(!q.empty() && d[i]<d[q.back()])	q.pop_back();
		q.push_back(i);
		if(i>=n-k)	ans = min(ans,a[i]-a[i-n+k+1]+d[q.front()]);
	}
	cout << ans;
	
	return 0;
}
