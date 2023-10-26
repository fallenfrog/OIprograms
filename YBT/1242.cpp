#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005];

int search(int l,int r){
	if(l>=r)	return l;
	int m = (l+r+1)>>1,cnt = 0;
	for(int i=1;i<=n;i++)
		cnt += a[i]/m;
	if(cnt>=k)	return search(m,r);
	else		return search(l,m-1);
}

int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		double t;
		cin >> t;
		a[i] = t*100;
	}
	printf("%.2lf",search(0,10000000)*1.0/100);
	
	return 0;
}
