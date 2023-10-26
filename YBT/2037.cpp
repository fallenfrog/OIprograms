#include<iostream>
using namespace std;
int a[1000],n,m,cnt,t,i;

int main(){
	cin >> n >> m;
	while(cnt<n){
		if(t==n) t=0;
		t++;
		if(!a[t]) i++;
		if(i==m){
			a[t] = 1;
			cout << t << ' ';
			cnt++;
			i=0;
		}
		
	}
	
	return 0;
} 
