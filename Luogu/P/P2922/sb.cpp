#include <bits/stdc++.h>
#define int long long
const int N = 1000010;
using namespace std;
int m,n,cnt;
int idx[N],sum[N];
int trie[N][2];//trie[i][j][k]表示第i号为0/1时下一层的编号 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>m>>n;
	memset(trie, -1, sizeof(trie));
	for(int i = 1;i<=m;i++) 
	{
		int sb;
		cin>>sb;
		int tmp=0;
		for(int j = 1;j<=sb;j++)
		{
			int x;
			cin>>x;
			sum[tmp]++;
			if(!(~trie[tmp][x])) trie[tmp][x]=++cnt;
			tmp=trie[tmp][x];
		}	
		idx[tmp]++;
		sum[tmp]++;
	} 
	for(int i = 1;i<=n;i++)
	{
		int sb;
		cin>>sb;
		int res=0,tmp=0;
		for(int j = 1;j<=sb;j++)
		{
			int x;
			cin>>x;
			res+=idx[tmp];
			if(tmp==-1) break;
			tmp=trie[tmp][x];
		}
		res+=sum[tmp];
		cout<<res<<"\n";
	}
	return 0;
}