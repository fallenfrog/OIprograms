#include<bits/stdc++.h>
using namespace std;
int f(int n){
	int ans=0;
	for(int i=1;i<=n;i++) ans+=n/i;
	return ans;
}
int main(){
	int t1,t2;
	cin>>t1>>t2;
	cout<<f(t2)-f(t1-1);
}

