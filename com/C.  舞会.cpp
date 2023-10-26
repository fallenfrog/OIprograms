#include<bits/stdc++.h>
using namespace std;
int n,a[200002],ans[100002][2],cnt,nxt[200002],pre[200002];
bool sex[200002],out[200002];
string s;
struct ele{
	int dif,a,b;
	bool operator >(const ele& other)const{
		return dif>other.dif || (dif==other.dif && a>other.a);
	}
};
priority_queue<ele,vector<ele>,greater<ele> > q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> s;
	cin >> a[1];	sex[1] = s[0]-'0';	pre[1] = -1;
	for(int i=2;i<=n;i++){
		cin >> a[i];
		pre[i] = i-1;
		if(i<n)	nxt[i] = i+1;
		else	nxt[i] = -1;
		sex[i] = s[i-1]-'0';
		if(sex[i]^sex[i-1]){
			q.push({abs(a[i]-a[i-1]),i-1,i});
		}
	}
	while(!q.empty()){
		ele t = q.top();
		q.pop();
			if(!(t.a==-1 || t.b==-1 || out[t.a] || out[t.b]) && sex[t.a]^sex[t.b]){
				ans[cnt][0] = t.a,ans[cnt][1] = t.b;
				out[t.a] = 1,	out[t.b] = 1;
				pre[nxt[t.b]] = pre[t.a];
				nxt[pre[t.a]] = nxt[t.b];
				q.push({abs(a[pre[t.a]]-a[nxt[t.b]]),pre[t.a],nxt[t.b]});
//				printf("%d %d %d\n",pre[t.a],nxt[t.b],abs(a[pre[t.a]]-a[nxt[t.b]]));
				cnt++;
			}
	}
	cout << cnt << '\n';
	for(int i=0;i<cnt;i++){
		cout << ans[i][0] << ' ' << ans[i][1] << '\n';
	}

	return 0;
}

