#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[300005],ans[300005];
deque<int> minn;

void update(int idx){
	cin >> a[idx];
	while(!minn.empty() && a[minn.back()]>a[idx])	minn.pop_back();
	minn.push_back(idx);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		update(i);
		ans[i] = a[minn.front()];
	}
	for(int i=m;i<n;i++){
		update(i);
		if(minn.front()<=i-m){
			minn.pop_front();
		}
		ans[i] = a[minn.front()];
	}
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		cout << ans[t-1] << '\n';
	}
	
	return 0;
}
