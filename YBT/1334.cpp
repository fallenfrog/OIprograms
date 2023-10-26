#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,idx=1;
int h[101],s[101];

void init(int n){
	s[1] = n;
	for(int i=1;i<n;i++){
		h[i] = i+1;
		s[i+1] = i;
	}h[n] = 1;
}

int main(){
	memset(h,-1,sizeof(h));
	cin >> n >> m;
	init(n);
	while(h[idx]!=idx){
		if(cnt==m){
			h[s[idx]] = h[idx];
			s[h[idx]] = s[idx];
			cnt = 0;
			cout << idx << ' ';
		}
		idx = h[idx];
		cnt++;
	}
	cout << idx;
	
	return 0;
}
