#include<bits/stdc++.h>
using namespace std;
int num[1002],d[1002],n,l,ans1,ans2;
bool a[1002];

int main(){
	d[ans1] = -1;
	cin >> l >> n;
	for(int i=1;i<=n;i++){
		int b,e;
		cin >> b >> e;
		d[i] = e-b;
		if(d[i]>d[ans1])	ans1 = i;
		for(int j=b;j<=e;j++){
			if(!a[j]){
				a[j] = 1;
				num[i]++;
			}
		}
		if(num[ans2]<num[i])	ans2 = i;
	}
	cout << ans1 << '\n' << ans2;
	
	return 0;
}
