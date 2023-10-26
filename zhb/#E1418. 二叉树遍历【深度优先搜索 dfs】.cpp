#include<bits/stdc++.h>
using namespace std;
string fs,ms,bs;

void getbs(string fs,string ms){
	char root = fs[0];
	int pos = 0,len = fs.size();
	while(ms[pos++]!=root);	pos --;
	string lfs,lms,rfs,rms;
	if(pos!=0){
		lfs = fs.substr(1,pos);
		lms = ms.substr(0,pos);
		getbs(lfs,lms);
	}
	if(pos!=len-1){
		rfs = fs.substr(pos+1,len-pos-1);
		rms = ms.substr(pos+1,len-pos-1);
		getbs(rfs,rms);
	}
	cout << root;
}

int main(){
	cin >> fs >> ms;
	getbs(fs,ms);
	
	return 0;
}
