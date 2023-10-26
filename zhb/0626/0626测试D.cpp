#include<bits/stdc++.h>
using namespace std;
int n,ans,s,c,b,len,ok;
string str;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	cin >> n >> str;
		for(int i=0;i<n;i++){
			len = s = c = b = 0;
			for(int j=i;j<n;j++){
				len++;
				if(str[j]=='S')	s++;
				else if(str[j]=='B')	b++;
				else if(str[j]=='C')	c++;
				if(s==0){
					if(b!=c)	ans = max(ans,len);
				}else{
					if(b==0){
						if(s!=c)	ans = max(ans,len);
					}else{
						if(s!=b){
							if(c!=s && c!=b)	ans = max(ans,len);
						}
					}
				}
			}
//			if(s==c && s==0){
//				ans = b;
//				break;
//			}
		}
	cout << ans;
	
	return 0;
}
