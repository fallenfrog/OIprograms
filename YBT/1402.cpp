#include<bits/stdc++.h>
using namespace std;
string M,C,k;

string change(string M,string k){
	int lk = k.length();
	int lM = M.length();
	int direction,iM,ik,t;
	for(int i=0;i<lM;i++){
		direction = i%lk;
		ik = (int)toupper(k[direction])-65;
		if(toupper(M[i])-ik<65){
			iM = M[i]-ik+26;
		}else{
			iM = M[i]-ik;
		}
		M[i] = (char)iM;
	}
	return M;
}

int main(){
	cin >> k >> M;
	cout << change(M,k);
	
	return 0;
}
