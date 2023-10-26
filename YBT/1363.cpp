#include<bits/stdc++.h>
#define MAX 1048577
using namespace std;
bool tree[MAX];

int main(){
	int d,l;
	cin >> d >> l;
	int mod = pow(2,d-1);
	int len = 2*mod-1;
	l %= mod;
	if(l==0){
		cout << mod;
		return 0;
	}
	
	int ans = 0;
	while(l--){
		int s = 1;
		while(2*s<len){
			tree[s] = !tree[s];
			if(tree[s]){
				s *= 2;
			}else{
				s = s*2+1;
			}
		}
		ans = s;
	}
	cout << ans;
	
	return 0;
}
