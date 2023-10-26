#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
	int a,b;
}e[10005];

bool cmp(Node x,Node y){return x.a<y.a || (x.a==y.a && x.b<=y.b);}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> e[i].a >> e[i].b;
		
	sort(e+1,e+n+1,cmp);
	int l = e[1].a,r = e[1].b;
	for(int i=2;i<=n;i++){
		if(e[i].a>r){
			cout << "no";
			return 0;
		}
		r = max(r,e[i].b);
	}
	cout << l << " " << r;
	
	return 0;
}
