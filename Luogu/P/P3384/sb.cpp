#include <bitsdc++.h>
#define int long long
#define ls (x<<1)
#define rs (x<<1|1)
const int N = 400010;
using namespace std;
int n,m,r,mod;
int w[N],nw[N];//新的树序号
int fa[N],dep[N],siz[N],top[N],son[N];//top为重链顶部，son为重儿子 
int dfn[N],tot;//dfn序 
vector <int> e[N];
//线段树----------------------------------------- 
struct Segtree
{
	int l,r,sum,add;
}tree[2*N];

void pushup(int x)
{
	tree[x].sum=(tree[ls].sum+tree[rs].sum)%mod;
}
void pushdown(int x)
{
	if(!tree[x].add) return;
	int l=tree[x].l,r=tree[x].r;
	int mid=(l+r)>>1;
	tree[ls].add+=tree[x].add,tree[ls].add%=mod;
	tree[rs].add+=tree[x].add,tree[rs].add%=mod;
	tree[ls].sum=(tree[ls].sum+((mid-l+1)*tree[x].add))%mod;
	tree[rs].sum=(tree[rs].sum+((r-mid)*tree[x].add))%mod;
	tree[x].add=0;
}
void build(int x,int l,int r)
{
	tree[x].l=l,tree[x].r=r;
	if(l==r) 
	{
		tree[x].sum=nw[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid),build(rs,mid+1,r);
	pushup(x);
}

void update_add(int x,int s,int t,int k)
{
	int l=tree[x].l,r=tree[x].r;
	int mid=(l+r)>>1;
	if(s<=l&&r<=t)
	{
		tree[x].add+=k,tree[x].add%=mod;
		tree[x].sum=(tree[x].sum+(r-l+1)*k)%mod;
		return;
	}
	pushdown(x);
	if(s<=mid) update_add(ls,s,t,k);
	if(r>mid) update_add(rs,s,t,k);
	pushup(x); 
}

int query_add(int x,int s,int t)
{
	int l=tree[x].l,r=tree[x].r;
	int mid=(l+r)>>1;
	if(s<=l&&r<=t)	return tree[x].sum;
	pushdown(x);
	int ans=0;
	if(s<=mid) ans=(ans+query_add(ls,s,t))%mod;
	if(t>mid) ans=(ans+query_add(rs,s,t))%mod;
	return ans;
}
//线段树----------------------------------------- 

void update_tree(int x,int k)//修改子树 
{
	update_add(1,dfn[x],dfn[x]+siz[x]-1,k);
}

void update_path(int u,int v,int k)//修改u到v之间的路径 
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		update_add(1,dfn[top[u]],dfn[u],k);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	update_add(1,dfn[u],dfn[v],k);
}

int query_tree(int x)//查询子树和 
{
	return query_add(1,dfn[x],dfn[x]+siz[x]-1)%mod;	
} 

int query_path(int u,int v)//查询u到v之间的和 
{
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])	swap(u,v);
		ans=(ans+query_add(1,dfn[top[u]],dfn[u]))%mod;
		u=fa[top[u]];
	} 
	if(dep[u]>dep[v]) swap(u,v);
	ans=(ans+query_add(1,dfn[u],dfn[v]))%mod;
	return ans;
}

void dfs1(int u,int father,int depth)//预处理siz,fa,dep,son 
{
	fa[u]=father,dep[u]=depth,siz[u]=1;
	for(int i = 0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==father) continue;
		dfs1(v,u,depth+1);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}	
} 
void dfs2(int u,int topp)//建新的以dfn序为标号的树 
{
	dfn[u]=++tot,nw[tot]=w[u],top[u]=topp;
	if(!son[u]) return ;
	dfs2(son[u],topp);
	for(int i = 0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>r>>mod;//r为根节点序号 
	for(int i = 1;i<=n;i++) cin>>w[i];
	for(int i = 1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	dfs1(r,-1,1);
	dfs2(r,r);
	build(1,1,n);
	
	while(m--)
	{
		int opt,x,y,z;
		cin>>opt;
		if(opt==1)
		{
			cin>>x>>y>>z;
			update_path(x,y,z);
		}
		else if(opt==2)
		{
			cin>>x>>y;
			cout<<query_path(x,y)<<"\n";
		}
		else if(opt==3)
		{
			cin>>x>>z;
			update_tree(x,z);
		}
		else if(opt==4)
		{
			cin>>x;
			cout<<query_tree(x)<<"\n";
		}
		cout<<opt<<"  ";
		for(int i = 1;i<=n;i++) cout<<query_add(1,i,i)<<" "; 
		cout<<"\n";
	}
	return 0;
}
