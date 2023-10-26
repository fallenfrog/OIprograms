#include<iostream>
#include<string>
using namespace std;
int n=0;
char root;
string str;
struct Node{
	int n=0;char p,chi[2]={' ',' '};
}node[150];

void save(char s){
	if(n==str.size()-1) return;
	if(node[s].n<2){
		char t=str[++n];
		node[s].n++; 
		if(t!='.'){
			node[t].p = s;
			if(node[s].chi[0]==' ')
				node[s].chi[0] = t;
			else
				node[s].chi[1] = t;
			save(t);
		}else
			save(s);
	}else
		save(node[s].p);
}

void mid(char s){
	if(node[s].chi[0]!=' '){
		mid(node[s].chi[0]);
	}
	cout << s;
	if(node[s].chi[1]!=' '){
		mid(node[s].chi[1]);
	}
}

void behind(char s){
	if(node[s].chi[0]!=' '){
		behind(node[s].chi[0]);
	}
	if(node[s].chi[1]!=' '){
		behind(node[s].chi[1]);
	}
	cout << s;
}

int main(){
	getline(cin,str);
	root = node[str[0]].p = str[0];
	save(root);
	mid(root);cout << endl;
	behind(root);
	
	return 0;
}
