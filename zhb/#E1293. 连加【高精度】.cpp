#include<bits/stdc++.h>
using namespace std;
long long n;
int a[102],b[102],c[102],la,lb,lc;

int main(){
	cin >> n;
	int t = 1;
	while(n>0){
		int m = n%10;
		a[la++] = m;
		if(m+t>=10){
			b[lb++] = 0;
			t = 1;
		}else{
			b[lb++] = m+t;
			t = 0;
		}
		n /= 10;
	}
	if(t>0)	b[lb++] = t;
	if(b[0]&1){
		for(int i=la-1;i>=0;i--){
			if(a[i]&1 && i>0)
				a[i-1] += 10;
			a[i] >>= 1;
		}
		if(a[la-1]==0)	la--;
	}else{
		for(int i=lb-1;i>=0;i--){
			if(b[i]&1 && i>0)
				b[i-1] += 10;
			b[i] >>= 1;
		}
		if(b[lb-1]==0)	lb--;
	}
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			c[i+j] += a[i]*b[j];
		}
	}
	t = 0,lc = la+lb;
	for(int i=0;i<=lc;i++){
		c[i] += t;
		t = c[i]/10;
		c[i] %= 10;
	}
	while(c[lc--]==0);	lc++;
	for(int i=lc;i>=0;i--)	cout << c[i];
	
	return 0;
}
