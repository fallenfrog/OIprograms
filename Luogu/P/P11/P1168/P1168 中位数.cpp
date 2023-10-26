#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int n,t;
struct ele{
	int a,b;
	bool operator <(const ele& other)const{
		return a<other.a || (a==other.a && b<other.b); 
	}
};
tree<ele,null_type,less<ele>,rb_tree_tag,tree_order_statistics_node_update> tr;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		tr.insert({t,i});
		if(i&1){
			auto it = tr.find_by_order(i>>1);
			cout << it -> a << '\n';
		}
	}

	return 0;
}

