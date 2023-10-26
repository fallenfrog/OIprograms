#include<bits/stdc++.h>
#include"online_judge.h"
#define ll long long
using namespace std;
ll a,b,c,e[2000002],k=1;
//struct ele{
//	int d,idx;
//	bool operator<(const ele& other)const{
//		return d<other.d;
//	}
//};
unordered_map<int,int> m;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> a >> b >> c;
	m[1] = e[0] = k++;
	for(int i=1;i<=1000000;i++){
		e[i] = e[i-1]*a+e[i-1]%b;
		e[i] %= c;
		if(m[e[i]]!=0){
			cout << i;
			return 0;
		}else{
			m[e[i]] = k++;
		}
	}
	cout << -1;
	
	return 0;
}
