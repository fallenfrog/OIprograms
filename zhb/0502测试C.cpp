#include<bits/stdc++.h>
#define mod 1991
using namespace std;
int n,a[50005],cnt;

void gbsort(int l,int r){
	if(l>=r)	return ;
	int m = (l+r)>>1;
	gbsort(l,m);
	gbsort(m+1,r);
	int i = l,j = m+1,k = l,c[50005];
	while(i<=m && j<=r){
		if(a[i]<=a[j]){
			c[k++] = a[i++];
		}else{
			cnt += m-i+1;
			c[k++] = a[j++];
		}
	}
	while(i<=m)	c[k++] = a[i++];
	while(j<=r)	c[k++] = a[j++];
	for(int i=l;i<=r;i++){
		a[i] = c[i];
	}
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	gbsort(1,n);
	int ans = 1,b = 2;
	while(cnt>0){
		if(cnt&1)	ans = ans*b%mod;
		b = b*b%mod;
		cnt >>= 1;
	}
	cout << ans;
	
	return 0;
}
