#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=10010;
int n,m,x,y,index_,dfn[maxn],low[maxn],ans,a;
vector<int>G[maxn];
struct Edge{int from,to;}edge[maxn];
bool cmp(const Edge a,const Edge b){if(a.from!=b.from)return a.from<b.from;return a.to<b.to;}
inline void add_edge(int x,int y){edge[ans].from=min(x,y);edge[ans].to=max(x,y);ans++;}
void dfs(int cur,int fa)
{
    int child;
    dfn[cur]=++index_;
    low[cur]=dfn[cur];
    bool vis=false; 
    for(int i=0;i<G[cur].size();i++)
    {
        child=G[cur][i];
        if(dfn[child])
		{
			if(child==fa&&!vis)vis=true;
			else low[cur]=min(low[cur],dfn[child]);
		}
        if(!dfn[child])
        {
            dfs(child,cur);
        	cerr << cur << ' ' << dfn[cur] << ' ' << child << ' ' << low[child] << '\n';
            if(dfn[cur]<low[child])add_edge(cur,child);
            low[cur]=min(low[cur],low[child]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
    for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,i);
    sort(edge,edge+ans,cmp);
    for(int i=0;i<ans;i++)printf("%d %d\n",edge[i].from,edge[i].to);
    return 0;
}