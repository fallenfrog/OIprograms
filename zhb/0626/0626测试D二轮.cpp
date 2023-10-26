#include<bits/stdc++.h>
using namespace std;
int n,s,b,c,a[1000002],ans;
string str;

bool check(int s,int b,int c){
	return ((s==0 && b==0) || (s==0 && c==0) || (b==0 && c==0)) || (s!=b && s!=c && b!=c);
}

int main(){
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	cin >> n >> str;
	for(int i=0;i<n;i++){
		if(str[i]=='S')		a[i] = 1,s++;
		else if(str[i]=='B')a[i] = 2,b++;
		else				a[i] = 3,c++;
	}
	if(check(s,b,c)){
		cout << n;
		return 0;
	}
	if(n>=500){
		int t[4];	t[1] = s,t[2] = b,t[3] = c;
		for(int i=n-1;i>n-4;i--){
			t[a[i]]--;
			if(check(t[1],t[2],t[3])){
				ans = max(ans,i);
			}
		}
		for(int i=0;i<3;i++){
			t[a[i]]--;
			for(int k=n-3;k<n;k++){
				t[a[k]]++;
			}
			if(check(t[1],t[2],t[3])){
				ans = max(ans,n-i-1) ;
			}
			for(int j=n-1;j>n-4;j--){
				t[a[j]]--;
				if(check(t[1],t[2],t[3])){
					ans = max(ans,j-i-1);
				}
			}
		}
	}else{
		int t[4];
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				t[1] = t[2] = t[3] = 0;
				for(int k=i;k<=j;k++){
					t[a[k]]++;
				}
				if(check(t[1],t[2],t[3])){
					ans = max(ans,j-i+1);
//					cout << t[1] << ' ' << t[2] << ' ' << t[3] << ' ' << ans << '\n';
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}
