#include<bits/stdc++.h>
using namespace std;
int L,n,cnt,t,tot,len[70],nxt[70];
bool vis[62],ok;
bool cmp(int x,int y){return x>y;}

void dfs(int idx,int last,int rest){
	int i;
	if(!rest){
		if(idx==tot){
			ok = 1;
			cout << L;
			return ;
		}
		for(i=1;i<=cnt;i++)
			if(!vis[i])	break;
		vis[i] = 1;
		dfs(idx+1,i,L-len[i]);
		vis[i] = 0;
		if(ok)	return ;
	}
	int l = last+1,r = cnt;
	while(l<r){
		int mid = (l+r)>>1;
		if(len[mid]<=rest)	r = mid;
		else	l = mid+1;
	}
	for(i=l;i<=cnt;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(idx,i,rest-len[i]);
			vis[i] = 0;
			if(ok)	return ;
			if(rest==L || rest==len[i])	return ;
			i = nxt[i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;	int sum = 0;
	for(int i=1;i<=n;i++){
		cin >> t;
		if(t>50)	continue;
		len[++cnt] = t;
		sum += t;
	}
	sort(len+1,len+cnt+1,cmp);
	nxt[cnt] = cnt;
	for(int i=cnt-1;i>0;i--){
		if(len[i]==len[i+1])	nxt[i] = nxt[i+1];
		else	nxt[i] = i;
	}
	for(L=len[1];L<=(sum>>1);L++){
		if(sum%L)	continue;
		tot = sum/L;
		vis[1] = 1;
		dfs(1,1,L-len[1]);
		vis[1] = 0;
		if(ok)	return 0;
	}
	cout << sum;
	
	return 0;
}
/*
64 
2 1 2 1 1 1 2 2 2 1 1 2 1 2 2 2 2 1 2 2 2 2 1 2 2 2 2 2 2 2 1 1 2 1 2 2 1 1 1 2 1 1 2 2 2 2 2 2 2 2 1 1 2 2 2 2 2 1 1 2 2 2 1 1
*/
