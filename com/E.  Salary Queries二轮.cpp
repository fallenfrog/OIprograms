#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define pair pair<int, int>
using namespace std;
using namespace __gnu_pbds;
tree<pair,null_type,less<pair>,rb_tree_tag,tree_order_statistics_node_update> tr;
int n,q,a[200002],l,r;
char c;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		tr.insert({a[i],i});
	}
	while(q--){
		cin >> c >> l >> r;
		if(c=='!'){
			tr.erase({a[l],l});
			tr.insert({r,l});
			a[l] = r;
		}
		if(c=='?'){
			int len = tr.order_of_key({r,INF})-tr.order_of_key({l,0});
			cout << len << '\n';
		}
	}

	return 0;
}
