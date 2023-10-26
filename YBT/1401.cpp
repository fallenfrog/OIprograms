#include<bits/stdc++.h>
using namespace std;
int a[10000],head,tail,m,n,temp,k,cnt;

int main(){
	memset(a,-1,sizeof(a));
	head = tail = 0;
	cin >> m >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		for(k=head;k<=tail;k++){
			if(a[k]==temp) break;
		}
		if(k==tail+1){
			a[++tail] = temp;
			if(tail-head==m){
				head++;
			}
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
