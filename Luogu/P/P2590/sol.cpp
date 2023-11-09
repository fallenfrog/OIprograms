#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P2590";
const int N = 3e4 + 2;
const int INF = 2e9;

int n, h[N], k, u, v, val[N], q;
string op;
struct edge{
    int v, nxt;
}e[N << 1];

int fa[N], siz[N], son[N], dep[N], bel[N], nv[N], dfn[N], tim;
void dfs1(int x){
    siz[x] = 1, dep[x] = dep[fa[x]] + 1;
    for(int i = h[x]; i; i = e[i].nxt){
        int v = e[i].v;
        if(v == fa[x])  continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[son[x]] < siz[v])  son[x] = v;
    }
}

void dfs2(int x, int b){
    dfn[x] = ++ tim, nv[tim] = val[x], bel[x] = b;
    if(son[x])  dfs2(son[x], b);
    for(int i = h[x]; i; i = e[i].nxt){
        int v = e[i].v;
        if(v == fa[x] || v == son[x])  continue;
        dfs2(v, v);
    }
}

struct SegTree{
#define ls (idx << 1)
#define rs (idx << 1 | 1)
#define mid (d[idx].l + d[idx].r >> 1)
    struct node{
        int l, r, s, mx, b;
    }d[N << 2];

    void push_up(int idx){
        d[idx].s = d[ls].s + d[rs].s,
        d[idx].mx = max(d[ls].mx, d[rs].mx);
    }

    void build(int l, int r, int idx){
        d[idx] = {l, r, 0, 0, 0};
        if(l == r){
            d[idx].s = d[idx].mx = nv[l];
            return ;
        }
        build(l, mid, ls), build(mid + 1, r, rs);
        push_up(idx);
    }

    void update(int pos, int k, int idx){
        if(d[idx].l == d[idx].r){
            d[idx].s = d[idx].mx = k;
            return ;
        }
        if(pos <= mid)  update(pos, k, ls);
        else  update(pos, k, rs);
        push_up(idx);
    }

    int query_sum(int l, int r, int idx){
        if(d[idx].r < l || r < d[idx].l)  return 0;
        if(l <= d[idx].l && d[idx].r <= r)  return d[idx].s;
        return query_sum(l, r, ls) + query_sum(l, r, rs);
    }

    int query_max(int l, int r, int idx){
        if(d[idx].r < l || r < d[idx].l)  return -INF;
        if(l <= d[idx].l && d[idx].r <= r)  return d[idx].mx;
        return max(query_max(l, r, ls), query_max(l, r, rs));
    }
}tree;

void update(int pos, int k){
    tree.update(dfn[pos], k, 1);
}

int query_sum(int l, int r){
    int res = 0;
    while(bel[l] != bel[r]){
        if(dep[bel[l]] < dep[bel[r]])  swap(l, r);
        res += tree.query_sum(dfn[bel[l]], dfn[l], 1);
        l = fa[bel[l]];
    }
    if(dep[l] > dep[r])  swap(l, r);
    return res + tree.query_sum(dfn[l], dfn[r], 1);
}

int query_max(int l, int r){
    int res = -INF;
    while(bel[l] != bel[r]){
        if(dep[bel[l]] < dep[bel[r]])  swap(l, r);
        res = max(res, tree.query_max(dfn[bel[l]], dfn[l], 1));
        l = fa[bel[l]];
    }
    if(dep[l] > dep[r])  swap(l, r);
    return max(res, tree.query_max(dfn[l], dfn[r], 1));
}

int main(){
    // FileIO();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i ++){
        cin >> u >> v;
        e[++ k] = {u, h[v]}, h[v] = k;
        e[++ k] = {v, h[u]}, h[u] = k;
    }
    for(int i = 1; i <= n; i ++)  cin >> val[i];
    dfs1(1);
    dfs2(1, 1);
    tree.build(1, n, 1);
    cin >> q;
    while(q --){
        cin >> op >> u >> v;
        if(op[0] == 'C'){
            update(u, v);
        }
        else if(op[1] == 'M'){
            cout << query_max(u, v) << '\n';
        }
        else{
            cout << query_sum(u, v) << '\n';
        }
    }
    
    return 0;
}