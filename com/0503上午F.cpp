#include<bits/stdc++.h>
using namespace std;
int ans,al,ar,l,r,k,len=1,idx[20005];
string o,s;
char c;

int main(){
	s.push_back('#');
	memset(idx,-1,sizeof(idx));
	while((c=getchar())!=EOF){
		o.push_back(c);
		if(c>='A' && c<='Z')	c += 32;
		if(c>='a' && c<='z'){
			s.push_back(c);
			idx[len++] = k;
			s.push_back('#');
			len++;
		}
		k++;
	}
	for(int i=0;i<len;i++){
		l = r = i;
		while(l>0 && r<len-1 && s[l]==s[r]){
			l--;
			r++;
		}
		l = l+1+(l&1);
		r = r-1-(r&1);
		if(idx[l]==-1 || idx[r]==-1)	continue;
		int cnt = 1+(r-l+1)>>1;
		if(cnt>ans){
			ans = cnt;
			al = l;
			ar = r;
		}
	} 
	cout << ans << '\n';
	for(int i=idx[al];i<=idx[ar];i++){
		cout << o[i];
	}
	
	return 0;
}
