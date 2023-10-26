#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m[1002],lm;
string sm;

signed main(){
	cin >> n >> sm;
	lm = sm.size();
	for(int i=0;i<lm;i++)	m[i] = sm[lm-i-1]-'0';
	for(int i=lm-1;i>0;i--){
		m[i] %= n;
		m[i-1] += m[i]*10;
	}
	cout << m[0]%n;
	
	return 0;
}
