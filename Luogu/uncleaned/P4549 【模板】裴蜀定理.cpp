#include<bits/stdc++.h>
using namespace std;
int n,ans,t;

int gcd(int a,int b){
	if(!(a%b))	return b;
	return gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> ans;
	for(int i=1;i<n;i++){
		cin >> t;
		if(t<0)	t = -t;
		if(t==0)	continue;
		if(t<ans)	swap(ans,t);
		ans = gcd(t,ans);
	}
	cout << ans;

	return 0;
}

