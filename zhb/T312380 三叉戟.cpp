#include<bits/stdc++.h>
using namespace std;
int f[60],ch[60][3],n,root;
bool vis[60];
unordered_map<char,int> m1;
unordered_map<int,char> m2;

void init(){
	char c = 'A';
	for(int i=1;c<='Z';i++,c++){
		m1[c] = i;	m2[i] = c;
	}
	c = 'a';
	for(int i=27;c<='z';i++,c++){
		m1[c] = i;	m2[i] = c;
	}
	m1['*'] = 0;	m2[-1] = '*';
}
bool letters(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

void yxx(int fa){
	if(fa==0)	return ;
	cout << m2[fa];
	yxx(ch[fa][0]);
	yxx(ch[fa][1]);
	yxx(ch[fa][2]);
}

void dzx(int fa){
	if(fa==0)	return ;
	dzx(ch[fa][1]);
	cout << m2[fa];
	dzx(ch[fa][2]);
	dzx(ch[fa][0]);
}

void yqx(int fa){
	if(fa==0)	return ;
	yqx(ch[fa][2]);
	yqx(ch[fa][0]);
	cout << m2[fa];
	yqx(ch[fa][1]);
}

int main(){
	init();
	cin >> n;
	string t;
//	memset(ch,-1,sizeof(ch));
	getline(cin,t);
	while(getline(cin,t)){
		char a = t[0],b = t[2],c = t[4],d = t[6];
		int ia = m1[a],ib = m1[b],ic = m1[c],id = m1[d];
		vis[ia] = vis[ib] = vis[ic] = vis[id] = 1;
		f[ib] = f[ic] = f[id] = ia;
		ch[ia][0] = ib;	ch[ia][1] = ic;	ch[ia][2] = id;	
	}
	for(int i=1;i<=52;i++){
		if(vis[i] && f[i]==0){
			root = i;
			break;
		}
	}
	yxx(root);	cout << '\n';
	dzx(root);	cout << '\n';
	yqx(root);
	
	return 0;
}
