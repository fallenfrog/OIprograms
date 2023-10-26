#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans=1;
bool vis[10];
map<int,int> cha;

signed main(){
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int a,b;
		cin >> a >> b;
		cha[a] = b;
	}
	
	while(n>0){
		int t = n%10,cnt = 1;
		memset(vis,0,sizeof(vis));
		vis[t] = 1;
		for(int i=cha[t];i!=0;i=cha[i]){
			if(!vis[i]){
				vis[i] = 1;
				cnt++;
			}else{
				break;
			}
		}
		ans *= cnt;
		n /= 10;
	}
	cout << ans;
	
	return 0;
}
