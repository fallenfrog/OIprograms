#include<bits/stdc++.h>
using namespace std;
#define L 10000000000
bool isp[100006];

void prime(int n){
	isp[1] = 1;
	for(int i=2;i<=n;i++){
		if(!isp[i]){
			for(int j=2;j*i<=n;j++){
				isp[i*j] = 1;
			}
		}
	}
}

int main(){
	int x,y,cnt=0;
	cin >> x >> y;
	prime(y);
	for(int i=x;i<=y;i++){
		if(!isp[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
