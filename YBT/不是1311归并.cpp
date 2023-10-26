#include<cstdio>
using namespace std;
int x,y,vis[27],a[21][21];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct Point{
	int x,y,cnt;
};

void dfs(Point p){
	for(int i=0;i<4;i++){
		
	}
}

int main(){
	scanf("%d%d",&y,&x);
	for(int i=1;i<=y;i++){
		for(int j=1;j<=x;j++){
			scanf("%d",a[j][i]);
			a[j][i] -= 64;
		}
	}
	dfs({1,1,1});
	
	return 0;
} 
