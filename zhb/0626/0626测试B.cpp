#include<bits/stdc++.h>
using namespace std;
int n,ok,cnt,n1;
int a[100002],idx[100002],ans[100002];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("lions.in","r",stdin);
	freopen("lions.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1)	ok = 1;
		idx[i] = i;
	}
	if(!ok){
		for(int i=1;i<=n;i++){
			if(!a[i]){
				ans[cnt++] = i;
			}else{
				n1++;
			}
		}
	}
	if(n1==2){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans[cnt++] = i;
				break;
			} 
		}
	}
	sort(ans,ans+cnt);
	cout << cnt << '\n';
	for(int i=0;i<cnt;i++){
		cout << ans[i] << ' ';
	}
	
	return 0;
}
