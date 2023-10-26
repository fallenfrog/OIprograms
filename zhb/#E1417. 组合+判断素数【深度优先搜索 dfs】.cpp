#include<bits/stdc++.h>
#define L 25000000
using namespace std;
int n,k,a[23],p[L+2],c=1,cnt;
bool ntp[L+2];

void GetPrime(){
	ntp[0] = ntp[1] = 1;
	for(int i=2;i<=L;i++){
		if(!ntp[i])	p[c++] = i;
		for(int j=1;j<c && i*p[j]<=L;j++){
			ntp[i*p[j]] = 1;
			if(i%p[j]==0)	break;
		}
	}
}

void dfs(int now,int sum,int num){
	if(now>k){
		if(sum<=L && !ntp[sum])
			cnt++;
		else{
			for(int i=1;i<c;i++)
				if(sum%p[i]==0)
					return ;
			cnt++;
		}
		return ;
	}
	for(int i=num;i<=n;i++)
		dfs(now+1,sum+a[i],i+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	GetPrime();
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	dfs(1,0,1);
	cout << cnt;
	
	return 0;
}
