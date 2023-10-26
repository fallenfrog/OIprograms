#include<iostream>
using namespace std;
int a[11451],n,m,t;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	} 
	cin >> m;
	for(int i=0;i<n;i++){
		if(m==a[i]){
			cout << i+1;
			t = 1;
			break;
		}
	}
	if(!t) cout << -1;
	
	
	return 0;
} 
