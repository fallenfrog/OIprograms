#include<bits/stdc++.h>
using namespace std;
const int N=205,INF=0x3f3f3f3f,nums[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char a[N][N];
struct S{
	int x,y,s,num;
};
bool vis[N][N][300];//˼��Ϊʲô��300�� 
inline char get_char(){//����getchar()����ո�ͻ��з� 
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
			if(a[i][j]=='S'){//��� 
				sx=i;
				sy=j;
			}else if(a[i][j]=='T'){//�յ� 
				tx=i;
				ty=j;
			}
		}
	}
	//���¿�ʼBFS 
	queue<S> q;
	q.push(S{sx,sy,0,0});//�ṹ���ĸ���ԱΪ������<x,y>,Կ�׶�����״̬,���� 
	vis[sx][sy][0]=true;//ע�����ά�ǳ���Կ�������������״̬�� 
	int ans=INF;
	while(!q.empty()){
		S st=q.front();
		q.pop();
		if(st.x==tx && st.y==ty) ans=min(ans,st.num);//�����յ㣬ע���ʱ������ֹ 
		for(int i=0;i<4;++i){//��ͨ�� 
			const int x=st.x+nums[i][0],y=st.y+nums[i][1];//��һ������<x,y> 
			if(0<=x && x<n && 0<=y && y<m && a[x][y]!='X'){//<x,y>�ڷ�Χ�ڲ��Ҳ���ǽ 
				if('A'<=a[x][y] && a[x][y]<='H' && !((st.s>>(a[x][y]-'A'))&1))//<x,y>���ţ���û��Կ�ף����������㣩 
					continue;//�����ߣ����������� 
				int s=st.s,num=st.num;
				if('a'<=a[x][y] && a[x][y]<='h'){//<x,y>��Կ�� 
					if(!((s>>(a[x][y]-'a'))&1)){//û�ù���Կ�ף�ֻ��һ�ѣ���ʾû�����ĵ㣩 
						s|=(1<<(a[x][y]-'a'));//����Կ�׵Ķ�����״̬ 
						++num;//����+1 
					}
				}
				if(!vis[x][y][s] && num<ans){//��֦��û�����Ҳ�������ans 
					q.push(S{x,y,s,num});//BFS��� 
					vis[x][y][s]=true;//���õ�ǰ״̬ 
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

