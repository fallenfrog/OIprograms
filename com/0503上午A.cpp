#include<bits/stdc++.h>
using namespace std;
string a,b,op;
bool na[100005],nb[100005],nc[100005];

int main(){
	cin >> a >> b >> op;
	int la = a.size(),lb = b.size();
	int ml = max(la,lb);
	for(int i=la;i>0;i--)	na[i] = a[la-i]-'0';
	for(int i=lb;i>0;i--)	nb[i] = b[lb-i]-'0';
	if(op[0]=='a'){
		for(int i=1;i<=ml;i++){
			nc[i] = na[i]&&nb[i];
		}
	}
	if(op[0]=='o'){
		for(int i=1;i<=ml;i++){
			nc[i] = na[i]||nb[i];
		}
	}
	if(op[0]=='x'){
		for(int i=1;i<=ml;i++){
			nc[i] = !(na[i]==nb[i]);
		}
	}
	while(ml>0 && !nc[ml--]);	ml++;
	for(int i=ml;i>0;i--){
		if(nc[i]){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	
	return 0;
}
