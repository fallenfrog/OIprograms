#include<bits/stdc++.h>
using namespace std;
int n,a[10000002],k,t;

int get(int l,int r,int x){
	int mid = (l+r+1)>>1;
	if(a[mid]==x || l>r){
		if(a[mid]==x){
			while(a[++mid]==x);
		}
		if(mid<=n)
			return mid;
		else
			return -1;
	}
	if(a[mid]>x)
		return get(l,mid-1,x);
	else
		return get(mid+1,r,x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cin >> k;
	for(int i=1;i<=k;i++){
		cin >> t;
		int tt = get(1,n,t);
		if(tt==-1)	cout << "no\n";
		else		cout << tt << '\n';
	}
	
	return 0;
}
