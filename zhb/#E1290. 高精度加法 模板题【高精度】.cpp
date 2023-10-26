#include<bits/stdc++.h>
using namespace std;
string sa,sb;
int a[102],b[102],c[102],la,lb,lc;

int main(){
	cin >> sa >> sb;
	la = sa.size(),lb = sb.size();
	for(int i=0;i<la;i++)	a[i] = sa[la-i-1]-'0';
	for(int i=0;i<lb;i++)	b[i] = sb[lb-i-1]-'0';
	for(int i=0;i<lb;i++)	a[i] += b[i];
	int t = 0,lc = max(la,lb);
	for(int i=0;i<=lc;i++){
		a[i] += t;
		t = a[i]/10;
		a[i] %= 10;
	}
	if(a[lc]>0)	cout << a[lc];
	for(int i=lc-1;i>=0;i--)	cout << a[i];
	
	return 0;
}
