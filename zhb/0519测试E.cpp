#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int n,k,app[300],ans[300];
struct power{
	int ba,po,nu;
	bool operator <(const power& other)const{
		return nu<other.nu || (nu==other.nu && ba<other.ba);
	}
}p[300];

int get(int n){
	if(ans[n]!=4557430888798830399LL)	return ans[n];
	if(n<4)	return ans[n] = n-1;
	int l=n,r=n,ta=0,tn=n;
	while(l>=0 || r<=200){
		if(app[l]!=0){
			ta = n-l+1;
			tn = app[l];
//			cout << n << ' ' << tn << ' ' << ta << endl;
			ans[n] = min(ans[n],ta+get(tn));
		}
		if(app[r]!=0){
			ta = r-n+1;
			tn = app[r];
//			cout << n << ' ' << tn << ' ' << ta << endl;
			ans[n] = min(ans[n],ta+get(tn));
		}
		if(l>=0)	l--;
		if(r<=200)	r++;
	}
	return ans[n];
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	if(n<4){
		cout << n-1;
		return 0;
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=2;i<=10;i++){
		int t = i;
		for(int j=2;t<=200;j++){
			t *= i;
			if(app[t]==0)	app[t] = i;
			p[k++] = {i,j,t};
		}
	}
	sort(p,p+k);
//	for(int i=0;i<k;i++){
//		cout << p[i].ba << ' ' << p[i].po << ' ' << p[i].nu << ' ' << app[p[i].nu] << '\n';
//	}
	cout << get(n);
	
	return 0;
}
