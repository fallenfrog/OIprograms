#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P1967";
const int N = 1e4 + 2;
const int M = 5e4 + 2;

int n, m, u, v, w, cnt, k, q;
int val[N << 1], h[N << 1], f[N << 1];
struct _edge{
    int u, v, w;
}eg[M];
struct edge{
    int v, nxt;
}e[N << 3];

int find(int x){return x == f[x] ? x : (f[x] = find(f[x]));}

int fa[N << 1], siz[N << 1], son[N << 1], bel[N << 1], dep[N << 1];
void dfs1(int x){
    siz[x] = 1, dep[x] = dep[fa[x]] + 1;
    for(int i = h[x]; i; i = e[i].nxt){
        int v = e[i].v;
        if(v == fa[x])  continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[v] > siz[son[x]])  son[x] = v;
    }
}

void dfs2(int x, int b){
    bel[x] = b;
    if(son[x])  dfs2(son[x], b);
    for(int i = h[x]; i; i = e[i].nxt){
        int v = e[i].v;
        if(v == son[x] || v == fa[x])  continue;
        dfs2(v, v);
    }
}

int lca(int a, int b){
    while(bel[a] != bel[b]){
        if(dep[bel[a]] < dep[bel[b]])  b = fa[bel[b]];
        else  a = fa[bel[a]];
    }
    return dep[a] < dep[b] ? a : b;
}

int main(){
    //FileIO();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;  cnt = n;
    for(int i = 1; i <= (n << 1); i ++)  f[i] = i;
    for(int i = 1; i <= m; i ++)  cin >> eg[i].u >> eg[i].v >> eg[i].w;
    sort(eg + 1, eg + m + 1, [](_edge a, _edge b){return a.w > b.w;});
    for(int i = 1; i <= m; i ++){
        int fu = find(eg[i].u),
            fv = find(eg[i].v);
        if(fu == fv)  continue;
        f[fu] = f[fv] = ++ cnt;
        val[cnt] = eg[i].w;
        // cerr << eg[i].u << "-" << fu << ' ' << eg[i].v << '-' << fv << ' ' << cnt << ' ' << val[cnt] << '\n';
        e[++ k] = edge{cnt, h[fu]}, h[fu] = k;
        e[++ k] = edge{cnt, h[fv]}, h[fv] = k;
        e[++ k] = edge{fu, h[cnt]}, h[cnt] = k;
        e[++ k] = edge{fv, h[cnt]}, h[cnt] = k;
    }  cnt ++;
    for(int i = 1; i < cnt; i ++){
    	if(find(i) == i){
    		e[++ k] = edge{i, h[cnt]}, h[cnt] = k;
    		e[++ k] = edge{cnt, h[i]}, h[i] = k;
    	}
    }
    val[cnt] = -1;
    dfs1(cnt);
    dfs2(cnt, cnt);
    cin >> q;
    for(int i = 1; i <= q; i ++){
        cin >> u >> v;
        cout << val[lca(u, v)] << '\n';
    }

    return 0;
}