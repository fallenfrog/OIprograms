#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,k,a[10004],ans,l,r;

void get(){
	int m = (l+r+1)/2,cnt = 0;
	if(m==0)	m = 1;
	for(int i=1;i<=n;i++)
		cnt += a[i]/m;
	if(cnt>=k){
		l = m;
	}else{
		r = m-1;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		double t;
		cin >> t;
		a[i] = t*100;
	}
	sort(a+1,a+1+n);
	l = 0,r = 10000000;
	while(l<r){
		get();
	}
	printf("%.2lf",l*1.0/100);
	
	return 0;
} 
