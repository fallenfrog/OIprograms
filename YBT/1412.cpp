#include<bits/stdc++.h>
using namespace std;

int change(int n){
	int ans;
	if(n==1||n==0) return n;
	return n%2+10*change(n/2);
}

int main(){
	int temp,cnt0=0,cnt1=0,ans1=0,ans0=0;
	for(int i=1;i<=1000;i++){
		temp = change(i);
		while(temp>0){
			if(temp%10==1) cnt1++;
			else cnt0++;
			temp/=10;
		}
		if(cnt1>cnt0) ans1++;
		else ans0++;
		cnt0 = cnt1 = 0;
	}
	cout << ans1 << ' ' << ans0;
	return 0;
}
