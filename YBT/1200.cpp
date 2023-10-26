#include<bits/stdc++.h>
using namespace std;
int n,m;

int d(int x,int z){
	if(x==1)	return 1;
	int cnt = 0;
	for(int i=z;i<=x;i++){
		if(x%i==0){
			cnt += d(x/i,i);
		}
	}
	return cnt;
}

int main(){
	cin >> n;
	while(n--){
		cin >> m;
		cout << d(m,2) << '\n';
	}
	
	return 0;
}
