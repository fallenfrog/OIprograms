#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k;
bool dk[64];

int main(){
	cin >> n >> k;
	int m = 0;
	while(k!=0){
		dk[m++] = k&1;//最后m为二进制位数+1 
		k >>= 1;
	}
	cout << dk[n-1];
	for(int i=n-2;i>=0;i--){
		int ans = dk[i]^dk[i+1];
		cout << ans;
	}
	
	return 0;
}
