#include<bits/stdc++.h>
using namespace std;
int n,a,b;
struct ele{
	int num,idx;
	bool operator <(const ele& other)const{
		return num < other.num;
	}
};
priority_queue<ele> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> a >> b;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		q.push({t,i});
	}
	int i;
	for(i=0;q.top().num>i*a;i++){
		ele t = q.top();
		q.pop();
		q.push({t.num-b,t.idx});
	}
	cout << i;
	
	return 0;
}
