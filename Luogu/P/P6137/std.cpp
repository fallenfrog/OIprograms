#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
#define t(x,y) (x)*n+y
#define min(a,b) a<b?a:b
#define mod 1000000000
#define M 3200000
using namespace std;
struct node1{int x,y;}v[100005];
struct node2{int x,l,r;}s[M];
bool cmp(node1 a,node1 b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int mx=1e9,my=1e9;
int n,h[M],ne[M*2],to[M*2],tot=0,cnt=0;
map<int,int>bz;
ll ans=0,size[M];
void add(int a,int b)
{
	to[++tot]=b,ne[tot]=h[a],h[a]=tot;
	to[++tot]=a,ne[tot]=h[b],h[b]=tot;
}
void dfs(int u,int fa)
{
	size[u]=s[u].r-s[u].l+1;
	for(int i=h[u];i;i=ne[i])
	{
		if(to[i]==fa)continue;
		dfs(to[i],u),size[u]+=size[to[i]];//统计子树大小
	}
	for(int i=h[u];i;i=ne[i])
	{
		if(to[i]==fa)continue;
		ans=(ans+(n-size[to[i]])*size[to[i]]%mod)%mod;//统计贡献
	}
}
void init()
{
	for(int i=1;i<=n;i++)v[i].x-=mx-1,v[i].y-=my-1;//将整个图平移
	sort(v+1,v+1+n,cmp),cnt=1,s[1].x=v[1].x,s[1].l=s[1].r=v[1].y,bz[t(v[1].x,v[1].y)]=1;
	for(int i=2;i<=n;i++)//分块
	{
		if(v[i-1].x==v[i].x&&v[i-1].y+1==v[i].y)
		{
			bz[t(v[i].x,v[i].y)]=cnt,s[cnt].r=v[i].y;
		}
		else s[++cnt].x=v[i].x,s[cnt].l=s[cnt].r=v[i].y,bz[t(v[i].x,v[i].y)]=cnt;
	}
	for(int i=1;i<=cnt;i++)//建树
	{
		for(int j=s[i].l;j<=s[i].r;j++)
		{
			if(bz[t(s[i].x+1,j)])add(i,bz[t(s[i].x+1,j)]),j=s[bz[t(s[i].x+1,j)]].r;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i].x,&v[i].y),mx=min(mx,v[i].x),my=min(my,v[i].y);
	init();
	dfs(1,0);
	bz.clear(),tot=0,cnt=0,memset(h,0,sizeof(h)),memset(size,0,sizeof(size));
	for(int i=1;i<=n;i++)v[i].x+=mx-1,v[i].y+=my-1,swap(v[i].x,v[i].y);
	swap(mx,my);
	init();
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}