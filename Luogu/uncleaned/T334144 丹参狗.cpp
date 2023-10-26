#include<bits/stdc++.h>
using namespace std;
int n,L[5000002],R[5000002],idx[5000002],ans;
bool dog[5000002];

bool cmp(int x,int y){
	return L[x]<L[y] || (L[x]==L[y] && R[x]>R[y]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	int t;
	for(int i=1;i<=n;i++){
		cin >> t;
		L[i] = max(1,i-t),R[i] = min(i+t,n);
		idx[i] = i;
	}
	sort(idx+1,idx+n+1,cmp);
//	cout << idx[1] << endl;
	for(int i=1;i<=n;i++){
		if(dog[L[i]])	continue;
//		cout << endl << L[i] << ' ' << R[i] << endl;
		for(int j=L[i];j<=R[i];j++){
			dog[j] = 1;
//			cout << j << ' ';
		}
		ans++;
	}
	cout << ans;
	
	return 0;
}
