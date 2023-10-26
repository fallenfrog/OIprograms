#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mod 1000000
using namespace std;
string s,a,maxx,minn;
int n,mxn=0,mnn=INF;

int main(){
	getline(cin,s);
	int len = s.size();
	for(int i=0;i<len;i++){
		char c = s[i];
//		if(c=='\n')	break;
		if(c!=' ' && c!=','){
			a.push_back(c);
		}else{
			n = a.size();
			if(n==0)	continue;
			if(n>mxn){
				mxn = n;
				maxx = a;
			}
			if(n<mnn){
				mnn = n;
				minn = a;
			}
			a = "";
		}
	}
	cout << maxx << '\n' << minn;
	
	return 0;
}
