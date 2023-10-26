#include<bits/stdc++.h>
using namespace std;
int n,m;
int sprd[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char r[100][100];
bool ill[100][100];

void update(int x,int y){
	for(int i=0;i<4;i++){
		int dx = x+sprd[i][0];
		int dy = y+sprd[i][1];
		if(dx<n && dy<n && dx>=0 && dy>=0 && r[dx][dy]!='#'){
			r[dx][dy] = '@';
		}
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin >> r[j][i];
			if(r[j][i]=='@')
				ill[j][i] = 1;
		}
	
	cin >> m;
	while(--m){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(ill[j][i])
					update(j,i);
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(r[j][i]=='@')
					ill[j][i] = 1;
	}
	
	int cnt = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(ill[j][i])
				cnt++;
	cout << cnt;
	
	
	return 0;
}
