#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int> > q;

int main(){
	cin >> n;
	int o,t;
	for(int i=1;i<=n;i++){
		cin >> o;
		if(o==1){
			cin >> t;
			q.push(t);
		}
		if(o==2){
			cout << q.top() << endl;
		}
		if(o==3){
			q.pop();
		}
	}
	
	return 0;
}
