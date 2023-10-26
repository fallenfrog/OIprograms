#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a[501],b[501],c[501];

int main(){
	cin >> s1 >> s2;
	int l1 = s1.size();
	int l2 = s2.size();
	for(int i=0;i<l1;i++)	a[l1-i-1] = s1[i]-'0';
	for(int i=0;i<l2;i++)	b[l2-i-1] = s2[i]-'0';
	int maxl = max(l1,l2);
	for(int i=0;i<maxl;i++)	c[i] = a[i]+b[i];
	int t = 0;
	for(int i=0;i<=maxl;i++){
		c[i] += t;
		t = c[i]/10;
		c[i] %= 10;
	}
	while(c[maxl--]==0);
	maxl++;
	for(int i=maxl;i>=0;i--){
		cout << c[i];
	}
	
	return 0;
}
