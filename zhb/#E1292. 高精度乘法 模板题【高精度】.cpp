#include<bits/stdc++.h>
using namespace std;
string sa,sb;
int a[202],b[202],c[202],la,lb,lc;

int main(){
	cin >> sa >> sb;
	la = sa.size(),lb = sb.size();
	for(int i=0;i<la;i++)	a[i] = sa[la-i-1]-'0';
	for(int i=0;i<lb;i++)	b[i] = sb[lb-i-1]-'0';
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			c[i+j] += a[i]*b[j];
		}
	}
	int t = 0,lc = la+lb;
	for(int i=0;i<=lc;i++){
		c[i] += t;
		t = c[i]/10;
		c[i] %= 10;
	}
	while(c[lc--]==0);	lc++;
	for(int i=lc;i>=0;i--)	cout << c[i];
	
	return 0;
}
