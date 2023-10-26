#include<bits/stdc++.h>
using namespace std;
int n,m[1000001],cnt=1,idx=1;
int h[1000001],s[1000001];

void init(int n){
	s[1] = n;
	for(int i=1;i<n;i++){
		h[i] = i+1;
		s[i+1] = i;
	}h[n] = 1;
}

int main(){
	memset(h,-1,sizeof(h));
	cin >> n;
	for(int i=1;i<=n;i++)	cin >> m[i];
	init(n);
	int tm = m[1];
	while(h[idx]!=idx){
		if(cnt==tm){
			h[s[idx]] = h[idx];
			s[h[idx]] = s[idx];
			cnt = 0;	tm = m[h[idx]];
		}
		idx = h[idx];
		cnt++;
	}
	cout << idx;
	
	return 0;
}
