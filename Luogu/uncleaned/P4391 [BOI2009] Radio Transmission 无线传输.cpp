#include<bits/stdc++.h>
using namespace std;
int l,kmp[1000002];
string s;

int main(){
	cin >> l >> s;
	int j = -1;
	memset(kmp,-1,sizeof(kmp));
	for(int i=1;i<l;i++){
		while(~j && s[j+1]!=s[i])	j = kmp[j];
		if(s[j+1]==s[i])	j++;
		kmp[i] = j;
	}
	cout << l-kmp[l-1]-1;

	return 0;
}

