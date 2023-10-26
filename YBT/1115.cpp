#include<iostream>
using namespace std;
int n,a[10000],cnt[10000],maxx = 0;

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(maxx<a[i]) maxx = a[i];
		cnt[a[i]]++;
	}
	for(int i=0;i<=maxx;i++){
		cout << cnt[i] << endl;
	}
	
	return 0;
}
