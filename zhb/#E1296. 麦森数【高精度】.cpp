#include<bits/stdc++.h>
#define L 500
using namespace std;
struct lll{
	int num[1002],len;
	lll operator *(lll other){
		lll zhiyin = {{},0};
		for(int i=0;i<len;i++){
			for(int j=0;j<other.len;j++){
				zhiyin.num[i+j] += num[i]*other.num[j];
			}
		}
		zhiyin.len = min(len+other.len,L);
		int t = 0;
		for(int i=0;i<=zhiyin.len;i++){
			zhiyin.num[i] += t;
			t = zhiyin.num[i]/10;
			zhiyin.num[i] %= 10;
		}
		while(zhiyin.num[zhiyin.len--]==0);	zhiyin.len += 2;
		return zhiyin;
	}
};
int p;

int main(){
	cin >> p;
	cout << (int)(p/(log2(10)))+1 << '\n';
	lll ans = {{},1},base = {{},1};
	ans.num[0] = 1;
	base.num[0] = 2;
	while(p>0){
		if(p&1)	ans = ans*base;
		p /= 2;
		base = base*base;
	}
	ans.num[0] -= 1;
	int temp = 499;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=50;j++){
			cout << ans.num[temp--];
		}
		cout << '\n';
	}
	
	return 0;
}
