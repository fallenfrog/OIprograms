#include<bits/stdc++.h>
using namespace std;
string sa,sb;
int a[102],b[102],c[102],la,lb,lc;

int main(){
	cin >> sa >> sb;
	if(sa.size()<sb.size() || (sa.size()==sb.size() && sa<sb)){
		swap(sa,sb);
		cout << '-';
	}
	la = sa.size(),lb = sb.size();
	for(int i=0;i<la;i++)	a[i] = sa[la-i-1]-'0';
	for(int i=0;i<lb;i++)	b[i] = sb[lb-i-1]-'0';
	for(int i=0;i<lb;i++)	a[i] -= b[i];
	int t = 0;
	for(int i=0;i<la;i++){
		a[i] += t;
		if(a[i]<0){
			a[i] += 10;
			t = -1;
		}else
			t = 0;
	}
	while(a[la--]==0);	la++;
	for(int i=la;i>=0;i--)	cout << a[i];
	
	return 0;
}
