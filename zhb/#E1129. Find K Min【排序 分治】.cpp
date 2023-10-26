#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000002];

void k_sort(int l,int r){
	if(l==r && l==k)	return ;
	if(l<r){
		int pos = a[l];
		int i = l,j = r;
		while(i<j){
			while(i<j && a[j]>pos)	j--;
			if(i<j)	swap(a[j],a[i]);
			while(i<j && a[i]<=pos)	i++;
			if(i<j)	swap(a[j],a[i]);
		}
		a[i] = pos;
		if(i==k)	return ;
		if(i>k)	k_sort(l,i-1);
		else	k_sort(i+1,r);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	k_sort(1,n);
	cout << a[k];
	
	return 0;
}
