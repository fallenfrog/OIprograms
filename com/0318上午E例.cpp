#include<bits/stdc++.h>
using namespace std;
const int N=205,INF=0x3f3f3f3f,nums[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char a[N][N];
struct S{
	int x,y,s,num;
};
bool vis[N][N][300];//思考为什么是300？ 
inline char get_char(){//避免getchar()读入空格和换行符 
	char c;
	for(c=getchar();c==' ' || c=='\n';c=getchar()){}
	return c;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int sx,sy,tx,ty;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			a[i][j]=get_char();
			if(a[i][j]=='S'){//起点 
				sx=i;
				sy=j;
			}else if(a[i][j]=='T'){//终点 
				tx=i;
				ty=j;
			}
		}
	}
	//以下开始BFS 
	queue<S> q;
	q.push(S{sx,sy,0,0});//结构体四个成员为：坐标<x,y>,钥匙二进制状态,步数 
	vis[sx][sy][0]=true;//注意第三维是持有钥匙情况（二进制状态） 
	int ans=INF;
	while(!q.empty()){
		S st=q.front();
		q.pop();
		if(st.x==tx && st.y==ty) ans=min(ans,st.num);//到达终点，注意此时程序不终止 
		for(int i=0;i<4;++i){//四通道 
			const int x=st.x+nums[i][0],y=st.y+nums[i][1];//下一步坐标<x,y> 
			if(0<=x && x<n && 0<=y && y<m && a[x][y]!='X'){//<x,y>在范围内并且不是墙 
				if('A'<=a[x][y] && a[x][y]<='H' && !((st.s>>(a[x][y]-'A'))&1))//<x,y>是门，且没有钥匙（二进制运算） 
					continue;//不能走，跳过该坐标 
				int s=st.s,num=st.num;
				if('a'<=a[x][y] && a[x][y]<='h'){//<x,y>是钥匙 
					if(!((s>>(a[x][y]-'a'))&1)){//没拿过该钥匙（只有一把，表示没来过改点） 
						s|=(1<<(a[x][y]-'a'));//设置钥匙的二进制状态 
						++num;//步数+1 
					}
				}
				if(!vis[x][y][s] && num<ans){//剪枝：没来过且步数少于ans 
					q.push(S{x,y,s,num});//BFS入队 
					vis[x][y][s]=true;//设置当前状态 
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

