#include<bits/stdc++.h>
using namespace std;
int n,a[101],tot,cnt;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		tot += a[i];
	}
	int avg = tot/n;
	for(int i=1;i<=n;i++)
		a[i] -= avg;
	for(int i=1;i<=n;i++){
		a[i] += a[i-1];
		if(a[i]!=0)
			cnt++;
	}
	cout << cnt;
	
	return 0;
}
