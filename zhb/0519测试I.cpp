#include<bits/stdc++.h>
#define base 103
using namespace std;
unordered_map<string,bool> vis;
int mov[4] = {3,1,-1,-3};
struct board{
	string str;
	int p0,cnt;
}f;
board s = {"123804765",4,-1};

void bfs(){
	queue<board> q;
	q.push(f);
	vis[f.str] = 1;
	while(!q.empty()){
		board t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tp = t.p0+mov[i];
			if(tp>=0 && tp<9 && (tp/3==t.p0/3 || tp%3==t.p0%3)){
				board tt = t;
				tt.cnt++,tt.p0 = tp;
				swap(tt.str[t.p0],tt.str[tp]);
				if(!vis[tt.str]){
					if(tt.str==s.str){
						cout << tt.cnt;
						return ;
					}
					vis[tt.str] = 1;
					q.push(tt);
				}
			}
		}
	}
}

int main(){
	cin >> f.str;
	for(int i=0;i<f.str.size();i++){
		if(f.str[i]=='0'){
			f.p0 = i;
			break;
		}
	}
	f.cnt = 0;
	bfs();
	
	return 0;
}
