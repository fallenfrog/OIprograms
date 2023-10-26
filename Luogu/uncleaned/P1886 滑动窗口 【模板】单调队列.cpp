#include<bits/stdc++.h>
using namespace std;
struct ele{
	int data,idx;
};
deque<ele> qmax;
deque<ele> qmin;
int n,k,ans[2][1000005];

int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		int t;	cin >> t;
		while(!qmax.empty() && qmax.back().data<=t)	qmax.pop_back();
		while(!qmin.empty() && qmin.back().data>=t)	qmin.pop_back();
		qmax.push_back({t,i});	qmin.push_back({t,i});
		while(i-k >= qmin.front().idx)	qmin.pop_front();
		while(i-k >= qmax.front().idx)	qmax.pop_front();
		ans[0][i] = qmin.front().data;
		ans[1][i] = qmax.front().data;
	}
	for(int i=k;i<=n;i++)	cout << ans[0][i] << ' ';
	cout << endl;
	for(int i=k;i<=n;i++)	cout << ans[1][i] << ' ';
	
	return 0;
}
