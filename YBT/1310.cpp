#include<bits/stdc++.h>
using namespace std;
int n,a[10001];

int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	int cnt = 0;
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				cnt++;
			}
		}
	}
	cout << cnt;
	
	return 0;
}
