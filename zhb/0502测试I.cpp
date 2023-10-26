#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string names[10005];
unordered_map<string,int> p;

bool cmp(string x,string y){
	return p[x]>p[y] || (p[x]==p[y] && x<y);
}

int main(){
	cin >> n;
	string t;
	for(int i=0;i<n;i++){
		cin >> t;
		names[k++] = t;
	}
	cin >> m;
	int tt;
	for(int i=0;i<m;i++){
		cin >> t >> tt;
		p[t] += tt;
	}
	sort(names,names+k,cmp);
	for(int i=0;i<k;i++){
		cout << names[i] << ' ' << p[names[i]] << '\n';
	}
	
	return 0;
}
