#include<bits/stdc++.h>
using namespace std;
int n,ans;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		ans += min(a,b);
	}
	cout << ans;
	
	return 0;
}
