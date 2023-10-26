#include<bits/stdc++.h>
#define mod 32767
using namespace std;
int f[1000001];

int main(){
	f[1] = 1,f[2] = 2;
	for(int i=3;i<=1000000;i++)
		f[i] = (f[i-2]+2*f[i-1])%mod;
	
	int n;	cin >> n;
	while(n--){
		int k;	cin >> k;
		cout << f[k] << endl;
	}
	
	return 0;
}
