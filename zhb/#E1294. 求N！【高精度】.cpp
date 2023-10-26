#include<bits/stdc++.h>
using namespace std;
int n,a[1020],b[1020],c[1020],la,lb,lc;

int main(){
	cin >> n;
	a[0] = 1;	la = 1;
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		int t = 1;
		for(int i=0;t>0;i++){
			b[i] += t;
			t = b[i]/10;
			b[i] %= 10;
			lb = max(lb,i+1);
		}
		for(int i=0;i<la;i++){
			for(int j=0;j<lb;j++){
				c[i+j] += a[i]*b[j];
			}
		}
		t = 0,lc = la+lb;
		for(int i=0;t>0 || i==0;i++){
			c[i] += t;
			t = c[i]/10;
			c[i] %= 10;
			lc = max(lc,i+1);
		}
		while(lc>=0 && c[lc--]==0);	lc += 2;
		for(int i=0;i<=max(la,lc);i++){
			a[i] = c[i];
		}
		la = lc;
	}
	for(int i=la-1;i>=0;i--)	cout << a[i];
	
	return 0;
}
