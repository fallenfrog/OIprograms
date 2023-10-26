#include<bits/stdc++.h>
using namespace std;
bool isp[100005];

void prime(int n){
	isp[1] = 1;
	for(int i=2;i<=100000;i++){
		if(!isp[i]){
			for(int j=2;j*i<=100000;j++){
				isp[i*j] = 1;
			}
		}
	}
}

int fx(int n){
	int ans=0;
	while(n>0){
		ans *= 10;
		ans += n%10;
		n /= 10;
	}
	return ans;
}

int main(){
	int n,m;
	bool flag = false;
	cin >> m >> n;
	prime(n);
	for(int i=m;i<=n;i++){
		if(!isp[i]&&!isp[fx(i)]){
			if(!flag){
				cout << i;flag = true;
			}else{
				cout << ',' << i;
			}
		}
	}
	if(!flag) cout << "No";

	
	return 0;
}
