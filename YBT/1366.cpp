#include<bits/stdc++.h>
using namespace std;
string fc,mc;
map<char,int> len;

int ac(string fc,string mc){
	if(fc.size()<=1){
		len[fc[0]] = 1;
		return 1;
	}
	char root = fc[0];
	len[root] = 0;
	int l = fc.size();
	int i = -1;
	while(mc[++i]!=root);
	if(i!=0){
		len[root] += ac(fc.substr(1,i),mc.substr(0,i));
	}else{
		len[root] += ac(fc.substr(1),mc.substr(1));
	}
	if(i<l-1){
		len[root] += ac(fc.substr(i+1,l-i),mc.substr(i+1,l-i));
	}
	return len[root];
}

int main(){
	cin >> fc >> mc;
	ac(fc,mc);
	for(int i=0;i<fc.size();i++){
		string t(len[fc[i]],fc[i]);
		cout << t << endl;
	}
	
	return 0;
}
