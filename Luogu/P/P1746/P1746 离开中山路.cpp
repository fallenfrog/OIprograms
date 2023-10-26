#include<cstdio>
using namespace std;
int sx,sy,fx,fy,n,map[1001][1001];
int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct Point{
	int x,y,cnt;
};

void bfs

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			char ch;
			ch = getchar();
			if(ch!='\n'){
				map[i][j] = ch-48;
			}
		}
	}
	scanf("%d%d%d%d",sx,sy,fx,fy);
	dfs({sx,sy,0});
	
	return 0;
}
