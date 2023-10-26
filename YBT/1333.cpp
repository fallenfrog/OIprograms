#include<bits/stdc++.h>
using namespace std;
int b,n,a[10000000];
map<int,bool> vis;

int main(){
	while(cin>>b>>n){
		int idx = 1,p = 1;
		a[idx] = b;
		while(idx<=n){
			if(!vis[a[p]]){
				a[++idx] = a[p]*2+1;
				a[++idx] = a[p]*3+1;
				vis[a[p]] = 1;
			}
			p++;
		}
		sort(a+1,a+idx+1);
		cout << a[n] << endl;
	}
	
	return 0;
}
