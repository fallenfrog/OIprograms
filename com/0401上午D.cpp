#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int k;
unsigned long long dp[10],t[10],sum;

int main(){
	cin >> k;
	if(k==1){cout << 10;return 0;}
	for(int i=0;i<10;i++)	dp[i] = 1;
	while(k--){
		for(int i=0;i<10;i++){
			for(int j=0;j<5;j++){
				int tt = i+2-j;
				if(tt>=0 && tt<10){
					dp[i] += t[tt];
					dp[i] %= mod;
				}
			}
		}
		for(int i=0;i<10;i++){
			t[i] = dp[i];
			dp[i] = 0;
		}
	}
	for(int i=1;i<10;i++){
		sum += t[i];
		sum %= mod;
	}
	cout << sum;
	
	return 0;
}
