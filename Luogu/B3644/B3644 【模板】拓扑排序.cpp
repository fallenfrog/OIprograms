#include<bits/stdc++.h>
using namespace std;
int n,t,cnt[105];
vector<int> p[105];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		p[0].push_back(i);
		cnt[i]++;
		while(cin >> t){
			if(t==0)	break;
			p[i].push_back(t);
			cnt[t]++;
		}
	}
	queue<int> q;	q.push(0);
	while(!q.empty()){
		t = q.front();	q.pop();
		if(t!=0)	cout << t << ' ';
		for(int i=0;i<p[t].size();i++){
			cnt[p[t][i]]--;
			if(cnt[p[t][i]]==0){
				q.push(p[t][i]);
			}
		}
	}

	return 0;
}

