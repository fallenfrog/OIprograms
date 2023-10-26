#include<bits/stdc++.h>
using namespace std;
int a[3000001],f[3000001];
int n;
stack<int> s;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	
	s.push(1);
	for(int i=2;i<=n;i++){
		while(!s.empty() && a[i]>a[s.top()]){
			f[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	f[s.top()] = 0;
	for(int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	
	return 0;
}
