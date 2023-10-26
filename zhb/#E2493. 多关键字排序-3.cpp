#include<bits/stdc++.h>
using namespace std;
int n;
struct Pair{
	int a,b;
	bool operator <(const Pair& other)const{
		return a<other.a || (a==other.a && b<other.b);
	}
}p[10002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> p[i].a >> p[i].b;
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		cout << p[i].a << ' ' << p[i].b << '\n';
	
	return 0;
}
