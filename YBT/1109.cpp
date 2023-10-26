#include<iostream>
using namespace std;
int a[11451],n,m,t;

int main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j%i==0)
				a[j-1]=1-a[j-1];
		}
	}
	cout << 1;
	for(int i=1;i<n;i++){
		if(a[i]){
			cout << ',' << i+1;
		}
	}
	
	return 0;
} 
