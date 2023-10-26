#include<bits/stdc++.h>
#define mod 99999997
using namespace std;
struct ele{
	int data,idx;
	bool operator< (const ele& other)const{
		return data < other.data;
	}
}a[100002],b[100002];
int n,cnt,c[100002],t[100002],f[100002];

void gbsort(int l,int r){
	if(l>=r)	return ;
	int mid = (l+r)>>1;
	gbsort(l,mid);
	gbsort(mid+1,r);
	int i = l,j = mid+1,p = l;
	while(i<=mid && j<=r){
		if(c[i]<=c[j]){
			t[p++] = c[i++];
		}else{
			t[p++] = c[j++];
			cnt += mid-i+1;
			cnt %= mod;
		}
	}
	while(i<=mid)	t[p++] = c[i++];
	while(j<=r)		t[p++] = c[j++];
	for(i=l;i<=r;i++)	c[i] = t[i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].data;
		a[i].idx = i;
	}
	for(int i=1;i<=n;i++){
		cin >> b[i].data;
		b[i].idx = i;
	}
	sort(a+1,a+n+1);	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)	c[b[i].idx] = a[i].idx;
	gbsort(1,n);
	cout << cnt;
	
	return 0;
}
