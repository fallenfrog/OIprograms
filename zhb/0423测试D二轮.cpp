#include<bits/stdc++.h>
using namespace std;
int n,a[105],sum,cnt;

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum += a[i];
	}
	int aver = sum/n;
	for(int i=1;i<=n;i++)
		a[i] -= aver;
		
	sum = 0;
	for(int i=1;i<=n;i++){
		sum += a[i];
		if(sum!=0)	cnt++;
	}
	cout << cnt;
	
	return 0;
}
