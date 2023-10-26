#include<bits/stdc++.h>
using namespace std;
int n;
string t;

struct lll{
	int a[100],len;
	lll(string t){
		len = t.size();
		for(int i=0;i<100;i++)	a[i] = 0;
		for(int i=len;i>0;i--){
			a[i-1] = t[len-i]-'0';
		}
	}
	void add(lll x){
		len = max(len,x.len);
		for(int i=0;i<len;i++){
			a[i] += x.a[i];
		}
	}
	void update(){
		int t = 0;
		for(int i=0;i<100;i++){
			a[i] += t;
			t = a[i]/10;
			a[i] %= 10;
		}
		for(int i=99;i>=0;i--){
			if(a[i]!=0){
				len = i+1;
				return ;
			}
		}
	}
};

int main(){
	cin >> n;
	lll sum("");
	for(int i=1;i<=n;i++){
		cin >> t;
		lll m(t);
		sum.add(m);
	}
	sum.update();
	for(int i=sum.len-1;i>=0;i--){
		cout << sum.a[i];
	}
	
	return 0;
}
