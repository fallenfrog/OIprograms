//#include<bits/stdc++.h>
//using namespace std;
//int n,p=2,t;
//int a[1020],b[1020],c[1020],la,lb,lc;
//vector<int> ans;
//
//int main(){
//	cin >> n;
//	a[0] = 1; la = 1;
//	while(n>0){
//		if(n-p<=p)	p = n;
//		n -= p;
//		if(!ans.empty())	t = p - ans[ans.size()-1];
//		else				t = p;
//		ans.push_back(p);
//		memset(c,0,sizeof(c));
//		for(int i=0;i<=lb;i++){
//			b[i] += t;
//			t = b[i]/10;
//			b[i] %= 10;
//		}
//		if(b[lb]>0)	lb++;
//		for(int i=0;i<la;i++){
//			for(int j=0;j<lb;j++){
//				c[i+j] += a[i]*b[j];
//			}
//		}
//		t = 0,lc = la+lb;
//		for(int i=0;i<=lc;i++){
//			c[i] += t;
//			t = c[i]/10;
//			c[i] %= 10;
//		}
//		while(c[lc--]==0);	lc += 2;
//		for(int i=0;i<=max(la,lc);i++){
//			a[i] = c[i];
//		}
//		la = lc;
//		
//		p++;
//	}
//	for(int i=0;i<ans.size();i++)	cout << ans[i] << ' ';
//	cout << "\n";
//	for(int i=la-1;i>=0;i--)	cout << a[i];
//	
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
int n;
int a[1020],b[1020],c[1020],la,lb,lc,ans[30002],l,r;
bool m[30002];

int main(){
	cin >> n;
	a[0] = b[0] = 1;	la = lb = 1;
	l = r = 2;
	while(n>0){
		if(n<r){
			if(r-n==1){
				l++;
				a[r] = r+2;
			}else{
				a[r] = r;
				m[r-n] = 1;
			}
		}
		n -= r;
		r++;
	}
	for(int i=l;i<r;i++)
		if(!m[i])
			cout << i << ' ';
	cout << '\n';
	for(int w=l;w<r;w++){
		int t = 1;
		while(m[w])
			w++,t++;
		memset(c,0,sizeof(c));
		for(int i=0;i<=lb;i++){
			b[i] += t;
			t = b[i]/10;
			b[i] %= 10;
		}
		if(b[lb]>0)	lb++;
		for(int i=0;i<la;i++){
			for(int j=0;j<lb;j++){
				c[i+j] += a[i]*b[j];
			}
		}
		t = 0,lc = la+lb;
		for(int i=0;i<=lc;i++){
			c[i] += t;
			t = c[i]/10;
			c[i] %= 10;
		}
		while(c[lc--]==0);	lc += 2;
		for(int i=max(la,lc);i>=0;i--){
			a[i] = c[i];
		}
		la = lc;
	}
	for(int i=la-1;i>=0;i--)	cout << a[i];
	
	return 0;
}
