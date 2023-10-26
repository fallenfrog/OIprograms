#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],t,score[2];
bool tmp;
deque<int> q;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++)	cin >> a[i];
	for(int i=1;i<=n+m;i++){
		if(!q.empty() && q.front()<=i-m)	q.pop_front();
		if(i<=n){
			while(!q.empty() && a[q.back()]<a[i])	q.pop_back();
			q.push_back(i);
		}
		if(!q.empty() && i>=t+m){
			score[tmp] += a[q.front()];
			tmp = !tmp;
			t = q.front();
		}
	}
	cout << score[0]-score[1] << '\n' << score[1]-score[0];
	
	return 0;
}
