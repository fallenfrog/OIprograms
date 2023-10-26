#include<bits/stdc++.h>
using namespace std;
int n;

struct Node{
	int begin,end;
}e[1000001];

bool cmp(Node x,Node y){return x.end <= y.end;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		e[i] = {a,b};
	}
	sort(e,e+n,cmp);
	
	int ans = 1;
	Node t = e[0];
	for(int i=1;i<n;i++){
		if(t.end<=e[i].begin){
			t = e[i];
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}
