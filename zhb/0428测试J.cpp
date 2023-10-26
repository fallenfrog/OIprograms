#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int n,a[30002],nxt[30002],pre[30002],sum,min1,min2;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		nxt[i-1] = i;
		pre[i] = i-1;
	}
	pre[0] = n;
	int len = n;
	while(len>1){
		int cnt = 0,t = 0;
		for(int i=nxt[0];cnt<2;i=nxt[i]){
			sum += a[i],t += a[i];
			nxt[pre[i]] = nxt[i];
			pre[nxt[i]] = pre[i];
			cnt++;
		}
		for(int i=nxt[0];1;i=nxt[i]){
			if(i==0 || t<=a[i]){
				n++;	a[n] = t;
				nxt[n] = i;	nxt[pre[i]] = n;
				pre[n] = pre[i];	pre[i] = n;
				break;
			}
		}
		len--;
	}
	cout << sum;
	
	return 0;
} 
