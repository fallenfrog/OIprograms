#include<bits/stdc++.h>
using namespace std;
struct ele{
	int a,b;
}e[5002];
bool cmp(ele x,ele y){return x.a>y.a || (x.a==y.a && x.b>y.b);}
int n,dp[5002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)	cin >> e[i].a >> e[i].b;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)	dp[i] = 1;
	for(int i=n-1;i>0;i--){
		for(int j=i+1;j<=n;j++){
			if(e[i].b<e[j].b){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)	ans = max(ans,dp[i]);
	cout << ans;
	
	return 0;
}
//×î³¤ÉÏÉý 
