#include<bits/stdc++.h>
using namespace std;
int n,m;
char ma[302][302];
struct point{
	int x,y;
}tran[26][2],s,e;
bool vis[302][302];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> ma[j][i];
			if(ma[j][i]=='#')	vis[j][i] = 1;
			if(ma[j][i]=='@')	s = {j,i};
			if(ma[j][i]=='=')	e = {j,i};
			if(isupper(ma[j][i]))	tran[ma[j][i]-'A'][tran[ma[j][i]-'A'].x==0];
		}
	}

	return 0;
}

