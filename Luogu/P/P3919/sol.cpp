#include<bits/stdc++.h>
using namespace std;

inline void FileIO(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3919";
const int N = 1e6 + 2;

int n, m, a[N];

struct hjt{
#define lc d[idx].ls
#define rc d[idx].rs
#define mid (d[idx].l + d[idx].r >> 1)

    int tot, visions, roots[N];

    struct node{
        int l, r, ls, rs, v;
    }d[N << 4];

    int newtree(){
        d[++ tot] = d[1];
        roots[visions ++] = tot;
        return tot;
    }

    void build(int l, int r, int idx){
        d[idx] = {l, r, tot + 1, tot + 2, 0}, tot += 2;
        if(l == r){
            d[idx].v = a[l];
            return ;
        }
        build(l, mid, lc), build(mid + 1, r, rc);
        d[idx].v = d[lc].v + d[rc].v;
    }

    void add(int l, int r, int idx, int k){
        
    }
}tree;

int main(){
    //FileIO();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)  cin >> a[i];

    
    return 0;
}