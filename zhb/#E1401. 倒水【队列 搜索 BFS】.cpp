#include<bits/stdc++.h>
using namespace std;
int m,n,p,minn;
bool vis[101][101];
struct con{
	int a,b,cnt;
};

void bfs(){
	queue<con> q;
	vis[0][0] = 1;
	q.push({0,0});
	while(!q.empty()){
		con t = q.front();
		q.pop();
		for(int i=0;i<6;i++){
			con tt = t;	tt.cnt++;
			switch(i){
				case 0:tt.a = m;break;
				case 1:tt.b = n;break;
				case 2:tt.a = 0;break;
				case 3:tt.b = 0;break;
				case 4:{
					minn = min(tt.a,n-tt.b);
					tt.a -= minn,tt.b += minn;
					break;
				}
				case 5:{
					minn = min(tt.b,m-tt.a);
					tt.b -= minn,tt.a += minn;
					break;
				}
			}
			if(!vis[tt.a][tt.b]){
				if(tt.a==p || tt.b==p){
					cout << tt.cnt;
					return ;
				}
				vis[tt.a][tt.b] = 1;
				q.push(tt);
			}
		}
	}
	cout << "No Solution!";
}

int main(){
	cin >> m >> n >> p;
	bfs();
	
	return 0;
}
