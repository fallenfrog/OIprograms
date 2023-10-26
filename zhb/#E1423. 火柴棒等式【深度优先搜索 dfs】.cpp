#include<bits/stdc++.h>
using namespace std;
int n,a[3],num[1000],ans;

void dfs(int res,int idx){
	if(idx>1){
		if(num[a[0]+a[1]]==res){
			ans++;
//			cout << a[0] << '+' << a[1] << '=' << a[0]+a[1] << '\n';
//			cout << num[a[0]] << ' ' << num[a[1]] << ' ' << res << endl;
		}
		return ;
	}
	for(int i=0;i<1000;i++){
		if(res-num[i]>1){
			a[idx] = i;
			dfs(res-num[i],idx+1);
		}
	}
}

int main(){
	cin >> n;
	if(n<13){
		cout << 0;
		return 0;
	}
	num[0] = 6,num[1] = 2,num[2] = num[3] = num[5] = 5,num[4] = 4,num[6] = num[9] = 6,num[7] = 3,num[8] = 7;
	for(int i=10;i<1000;i++){
		int t = i;
		while(t>0){
			num[i] += num[t%10];
			t /= 10;
		}
	}
	n -= 4;
	dfs(n,0);
	cout << ans;
	
	return 0;
}
