#include<bits/stdc++.h>
using namespace std;
int n,k,a[10002],ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		double t;	cin >> t;
		a[i] = t*100;
	}
	int l = 0,r = 10000000;
	while(l<=r){
		int mid = (l+r)>>1,cnt = 0;
		if(mid==0){
			puts("0.00");
			return 0;
		}
		for(int i=1;i<=n;i++){
			cnt += a[i]/mid;
		}
		if(cnt>=k){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	printf("%.2lf",ans*1.0/100);
	
	return 0;
}
