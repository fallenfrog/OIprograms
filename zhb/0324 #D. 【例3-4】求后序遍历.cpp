#include<iostream>
#include<string>
using namespace std;
string q,z,h;

string cha(string q,string z){
	string s1,s2;
	if(q.size()<=1) return q;
	char root = q[0];int k;
	for(k=0;k<z.size();k++)
		if(z[k]==root) 
			break;
	s1=cha(q.substr(1,k),z.substr(0,k));
	if(k+1>=q.size()) s2="";
	else s2=cha(q.substr(k+1,q.size()-k-1),z.substr(k+1,z.size()-k-1));
	return s1+s2+root;
}

int main(){
	cin >> q >> z;
	cout << cha(q,z);
	
	return 0;
}
