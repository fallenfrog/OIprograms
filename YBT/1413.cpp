#include<bits/stdc++.h>
using namespace std;

int change(int n,int b){
	int ans;
	if(n<10) return n;
	return n%10+b*change(n/10,b);
}

int main(){
	int p,q,r,p1,q1,r1;
	cin >> p >> q >> r;
	for(int b=2;b<41;b++){
		p1 = change(p,b);
		q1 = change(q,b);
		r1 = change(r,b);
		if(p1*q1==r1){
			cout << b;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
