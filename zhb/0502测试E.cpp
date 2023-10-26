#include<bits/stdc++.h>
using namespace std;
int n,a[102],b[102];

int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		stack<int> s;
		int t;
		for(int i=1,j=1;i<=n&&j<=n;i++){
			s.push(a[i]);
			while(!s.empty() && s.top()==b[j]){
				s.pop();
				j++;
			}
		}
		if(!s.empty()){
			cout << "NO!\n";
		}else{
			cout << "YES!\n";
		}
	}
	
	return 0;
}
