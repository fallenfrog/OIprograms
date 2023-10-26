#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001],t[100001],cnt;

void gbsort(int l,int r){
	if(l>=r)	return ;
	int m = (r+l)/2;
	gbsort(l,m);
	gbsort(m+1,r);
	int i = l,j = m+1,c = l;
	while(i<=m && j<=r){
		if(a[i]>a[j]){
			t[c++] = a[j++];
			cnt+=m-i+1;
		}else{
			t[c++] = a[i++];
		}
	} 
	while(i<=m)	t[c++] = a[i++];
	while(j<=r)	t[c++] = a[j++];
	for(int i=l;i<=r;i++)	a[i] = t[i];
}

signed main(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	gbsort(0,n-1);
	cout << cnt;
	
	return 0;
}
