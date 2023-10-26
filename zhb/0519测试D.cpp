#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int a[8];
int ans,sum;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	for(int i=1;i<=7;i++){
		cin >> a[i];
		sum += a[i];
		ans += i*a[i];
	}
	if(sum==a[1]){
		cout << 1;
		return 0;
	}
	for(int i=7;i>1;i--){
		if(a[i]>0){
			ans += a[1]*i;
			break;
		}
	}
	stack<int> p;
	while(ans>0){
		p.push(ans%10);
		ans /= 10;
	}
	while(!p.empty()){
		cout << p.top();
		p.pop();
	}
	
	return 0;
}
