#include<bits/stdc++.h>
using namespace std;
int n,t;
vector<int> q;
vector<int> ans;

int main(){
	scanf("%d",&n);
	int t,f;
	while(1){
		scanf("%d",&t);
		q.push_back(t);
		if(t==-1) break;
		if(q.size()>=n){
			f = q.front();
			for(int i=1;i<n;i++){
				f = max(f,q[i]);
			}
			q.erase(q.begin());
			ans.push_back(f);
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
