#include<bits/stdc++.h>
using namespace std;
int n,cnt,t,sum,L,tot;
int len[70],nxt[70];
bool vis[70],ok;
bool cmp(int x,int y){return x>y;}

void dfs(int num,int idx,int rest){
	int i;
	if(!rest){
		if(num==tot){
			ok = 1;
			cout << L;
			return ;
		}
		for(i=2;i<=cnt;i++)	if(!vis[i])	break;
		vis[i] = 1;
		dfs(num+1,i,L-len[i]);
		vis[i] = 0;
		if(ok)	return ;
	}
	int l = idx+1,r = cnt,mid;
	while(l<r){
		mid = (l+r)>>1;
		if(rest<len[mid])	l = mid+1;
		else	r = mid;
	}
	for(i=l;i<=cnt;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(num,i,rest-len[i]);
			vis[i] = 0;
			if(ok)	return ;
			if(rest==len[i] || rest==L)	return ;
			i = nxt[i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		if(t>50)	continue;
		len[++cnt] = t;
		sum += t;
	}vis[1] = 1,nxt[cnt] = cnt;
	sort(len+1,len+cnt+1,cmp);
	for(int i=cnt-1;i>0;i--){
		if(len[i]==len[i+1])	nxt[i] = nxt[i+1];
		else	nxt[i] = i;
	}
	for(L=len[1];L<sum;L++){
		if(sum%L)	continue;
		tot = sum/L;
		dfs(1,1,L-len[1]);
		if(ok)	return 0;
	}
	cout << sum;
	
	return 0;
}
