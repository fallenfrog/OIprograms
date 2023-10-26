#include<bits/stdc++.h>
using namespace std;
struct ele{
	int l,r;
	bool operator <(const ele& other)const{
		return l<other.l || (l==other.l && r>other.r);
	}
}e[1002],f[1002];
int n,cnt,k;
bool out[1002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)	cin >> e[i].l >> e[i].r;
	sort(e+1,e+n+1);
	cnt = n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!out[j] && e[i].l<=e[j].l && e[i].r>=e[j].r){
				out[j] = 1;
				cnt--;
			}
		}
	}
	cout << cnt;

	return 0;
}

