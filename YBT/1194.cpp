#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n;
int s[20][20];

signed main(){
	cin >> m >> n;
	s[1][1] = 1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s[j+1][i] += s[j][i];
			s[j][i+1] += s[j][i];
		}
	}
	cout << s[n][m];
	
	return 0;
}
