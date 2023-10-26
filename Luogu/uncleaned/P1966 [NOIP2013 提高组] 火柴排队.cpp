#include<bits/stdc++.h>
#define mod 99999997
using namespace std;
int n,c[100002],d[100002],t[100002],ans;
struct ele{
	int num,idx;
	bool operator <(const ele& other)const{
		return num < other.num;
	}
}a[100002],b[100002];

void gbsort(int l,int r){
	if(l>=r)	return ;
	int mid = (l+r)>>1;
	gbsort(l,mid);	gbsort(mid+1,r);
	int i = l,j = mid+1,cnt = l;
	while(i<=mid && j<=r){
		if(d[i]<=d[j]){
			t[cnt++] = d[i++];
		}else{
			ans = (ans+mid-i+1)%mod;
			t[cnt++] = d[j++];
		}
	}
	while(i<=mid)	t[cnt++] = d[i++];
	while(j<=r)		t[cnt++] = d[j++];
	for(i=l;i<=r;i++){
		d[i] = t[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].num;
		a[i].idx = i;
	}
	for(int i=1;i<=n;i++){
		cin >> b[i].num;
		b[i].idx = i;
	}
	sort(a+1,a+n+1);	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)	d[a[i].idx] = b[i].idx;
//	for(int i=1;i<=n;i++)	c[a[i].idx] = i;
//	for(int i=1;i<=n;i++)	d[i] = c[b[i].idx];
	gbsort(1,n);
	cout << ans;
	
	return 0;
}
