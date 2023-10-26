#include<bits/stdc++.h>
using namespace std;
int V,v[30],g,c[30][20],dp[30][(1<<15)+3],num[(1<<15)+3],ans;
bool ok;

bool check(int a,int b){
	while(1){
		if(a&1 && !(b&1))	return 1;
		if(b&1 && !(a&1))	return 0;
		a>>=1;	b>>=1;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> V;
	for(int i=1;i<=V;i++)	cin >> v[i];
	cin >> g;
	for(int i=1;i<=g;i++){
		for(int j=1;j<=V;j++){
			cin >> c[j][i];
		}
	}
	ans = (1<<g)-1;	num[0] = 0,num[ans] = g;
	for(int i=1;i<(1<<g);i++){
		ok = 1;
		for(int j=1;j<=g;j++){
			if(i&(1<<j-1)){
				for(int k=1;k<=V;k++){
					dp[k][i] = dp[k][i^(1<<j-1)]+c[k][j];
					if(dp[k][i]<v[k])	ok = 0;
				}
				num[i] = num[i^(1<<j-1)]+1;
				if(ok){
					if(num[i]<num[ans] || (num[i]==num[ans] && check(i,ans))){
						ans = i;
					}
				}
				break;
			}
		}
	}
	cout << num[ans] << ' ';
	for(int i=1;ans;ans>>=1,i++){
		if(ans&1)	cout << i << ' ';
	}

	return 0;
}

