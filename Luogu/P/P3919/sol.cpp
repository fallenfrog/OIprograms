#include<bits/stdc++.h>
#define int long long
using namespace std;

inline void FileIO(string s){
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const string name = "P3919";
const int N = 2e6 + 2;

int n, m, a[N], v, op, l, k, t;

struct hjt{
#define lc d[idx].ls
#define rc d[idx].rs
#define mid (d[idx].l + d[idx].r >> 1)

    int tot, versions, roots[N];
	hjt(){
		tot = versions = 0;
		memset(roots, 0, sizeof(roots));
	}

	struct node{
        int l, r, ls, rs, v;
    }d[N * 20];

    void newtree(){
        roots[versions ++] = tot + 1;
    }

    void build(int l, int r, int &idx){
		idx = ++ tot;
		d[idx] = {l, r, 0, 0, 0};
		if(l == r){
            d[idx].v = a[l];
			return ;
		}
        build(l, mid, lc), build(mid + 1, r, rc);
    }

    void update(int pos, int idx, int k){
        d[++ tot] = d[idx];
        if(d[idx].l == d[idx].r){
            d[idx].v = k;
            return ;
        }
        if(pos <= mid)  update(pos, lc, k);
        else  update(pos, rc, k);
    }

    int query(int pos, int idx){
        if(d[idx].l == d[idx].r)  return d[idx].v;
        if(pos <= mid)  return query(pos, lc);
        else  return query(pos, rc);
    }
}tree;

signed main(){
    //FileIO();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++)  cin >> a[i];
    tree.newtree();
    tree.build(1, n, t);
    while(m --){
        cin >> v >> op >> l;
        if(op == 1){
            cin >> k;
            tree.newtree();
            tree.update(l, tree.roots[v], k);
        }else{
			tree.newtree();
			tree.d[++ tree.tot] = tree.d[tree.roots[v]];
			cout << tree.query(l, tree.tot) << '\n';
		}
    }
    
    return 0;
}