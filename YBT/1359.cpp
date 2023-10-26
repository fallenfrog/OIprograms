#include<bits/stdc++.h>
using namespace std;
int w;
bool a[10][10],vis[10][10];
struct Point{
	int x,y;
};

void bfs(int x,int y){
	if(!vis[x][y] && !a[x][y])
}

int main(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin >> a[i][j];
			w += a[i][j];
		}
	}
		
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			bfs(i,j);
		}
	}
	
	return 0;
}
