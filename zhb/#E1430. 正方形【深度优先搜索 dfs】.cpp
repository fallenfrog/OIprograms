#include<bits/stdc++.h>
using namespace std;
int n,sum,L,tot=4;
int len[30];
bool vis[30],ok;
bool cmp(int x,int y){return x>y;}

void dfs(int idx,int last,int rest){
	int i;
	if(!rest){
		if(idx==tot){ok=1;return;}
		for(i=2;i<=n;i++)	if(!vis[i])	break;
		vis[i] = 1;
		dfs(idx+1,i,L-len[i]);
		vis[i] = 0;
		if(ok)	return ;
	}
	int l = last+1,r = n,mid;
	while(l<r){
		mid = (l+r)>>1;
		if(len[mid]>rest)	l = mid+1;
		else	r = mid;
	}
	for(i=l;i<=n;i++){
		if(vis[i])	continue;
		vis[i] = 1;
		dfs(idx,i,rest-len[i]);
		vis[i] = 0;
		if(ok)	return ;
		if(rest==L || rest==len[i])	return ;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> len[i];
		sum += len[i];
	}
	sort(len+1,len+n+1,cmp);
	if(sum%4){
		cout << "no";
		return 0;
	}
	L = sum/4;
	vis[1] = 1;
	dfs(1,1,L-len[1]);
	if(ok)	cout << "yes";
	else	cout << "no";
	
	return 0;
}
