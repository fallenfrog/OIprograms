#include<bits/stdc++.h>
using namespace std;
int T,L,R,len,ans;
bool vis[2000002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> L >> R;
		if(L<10){
			cout << "0\n";
			continue;
		}else{
			memset(vis,0,sizeof(vis));	ans = 0;
			for(int t=10;;t*=10){
				if(L<t*10){
					len = t;
					break;
				}
			}
			for(int i=L;i<=R;i++){
				if(!vis[i]){
					int cnt = 1;
					for(int j=(i%10)*len+i/10;j!=i;j=(j%10)*len+j/10){
						if(j>=L && j<=R && !vis[j]){
							vis[j] = 1;
							cnt++;
						}
					}
					ans += (cnt-1)*cnt/2;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}

