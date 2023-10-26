#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define re register 
using namespace std;
typedef long long ll;
const int inf=1e9+7;
inline int read()
{
    int p=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){p=p*10+c-'0';c=getchar();}
    return f*p;}
const int maxn=300003;
struct Edge
{
    int from,to,w,id;
}p[maxn<<1];
struct query
{
    int x,y,lca,d;
}A[maxn];
int n,m,cnt,head[maxn<<1],C[maxn],dis[maxn];
int fa[maxn],depth[maxn],top[maxn],heavy[maxn],siz[maxn];
int val[maxn],dnf[maxn],tot,R,L;
inline void add_edge(int x,int y,int W)//加边 
{
    cnt++;
    p[cnt].from=head[x];
    head[x]=cnt;
    p[cnt].to=y;
    p[cnt].w=W;
}
inline void dfs1(int x,int f)
//树剖dfs1:处理每个点的父亲fa,深度depth,子树大小siz,dfs序dnf 
{
    fa[x]=f,depth[x]=depth[f]+1,siz[x]=1,dnf[++tot]=x;
    for(re int i=head[x];i;i=p[i].from)
        {
            int y=p[i].to;
            if(y==f)continue;
            val[y]=p[i].w;
            dis[y]=dis[x]+p[i].w;
            dfs1(y,x);
            siz[x]+=siz[y];
            if(!heavy[x]||siz[y]>siz[heavy[x]])
                heavy[x]=y;
        }
}
inline void dfs2(int x,int t)//树剖dfs2:处理重链 
{
    top[x]=t;
    if(!heavy[x])return ;
    dfs2(heavy[x],t);
    for(re int i=head[x];i;i=p[i].from)
        {
            int y=p[i].to;
            if(y==fa[x]||y==heavy[x])continue;
            dfs2(y,y);
        }
}
inline int LCA(int x,int y)//树剖求LCA 
{
    while(top[x]!=top[y])
        {
            if(depth[top[x]]<depth[top[y]])swap(x,y);
            x=fa[top[x]];
        }
    return depth[x]<=depth[y]?x:y;
}
//=================================以上是树剖常规操作
inline int check(int lim,int sum=0)//二分答案检验,如上所述 
{
    memset(C,0,sizof(C));//注意每一次都要清空C数组
    for(re int i=1;i<=m;i++)
        if(A[i].d>lim)//树上(边)差分
            {
                C[A[i].x]++,C[A[i].y]++,C[A[i].lca]-=2;
                sum++;
            }
    for(re int i=n;i>=1;i--)
        {
            C[fa[dnf[i]]]+=C[dnf[i]];//每次差分值都累加到父亲节点
            if(val[dnf[i]]>=R-lim&&C[dnf[i]]==sum)
            //存在一条路径满足上述条件则可行
            	return 1;
        }
    return 0;//否则无解
}
inline int Binary_search(int llim,int rlim,int mid=0)//二分答案 
{
    while(llim<rlim)
        {
            mid=(llim+rlim)>>1;
            if(check(mid))rlim=mid;
            else llim=mid+1;
        }
    return llim;
}
int main()
{
//	freopen("transport.in","r",stdin);
//	freopen("transport.out","w",stdout);
    //这是校内模拟赛的考试题= =光荣爆蛋 
    n=read(),m=read();
    for(re int i=1;i<n;i++)
        {
            int x=read(),y=read(),w=read();
            add_edge(x,y,w);
            add_edge(y,x,w);
            L=max(L,w);//统计最大边权 
        }
    dfs1(1,0);dfs2(1,1);//树剖预处理 
    for(re int i=1;i<=m;i++)//预处理每一次请求的lca和距离 
        {
            A[i].x=read(),A[i].y=read();
            A[i].lca=LCA(A[i].x,A[i].y);
            A[i].d=dis[A[i].x]+dis[A[i].y]-2*dis[A[i].lca];
            R=max(R,A[i].d);
        }
    printf("%d\n",Binary_search(R-L,R+1));//二分答案
    return 0;
}