#include<bits/stdc++.h>
using namespace std;
string s1,s2; 
int l1,l2,kmp[1000002];

int main(){
	cin >> s1 >> s2;
	l1 = s1.size(),l2 = s2.size();
	memset(kmp,-1,sizeof(kmp));
	int j = -1;
	for(int i=1;i<l2;i++){
		while(~j && s2[j+1]!=s2[i])	j = kmp[j];
		if(s2[j+1]==s2[i])	j++;
		kmp[i] = j;
	}
	j = -1;
	for(int i=0;i<l1;i++){
		while(~j && s2[j+1]!=s1[i])	j = kmp[j];
		if(s2[j+1]==s1[i])	j++;
		if(j==l2-1){
			cout << i+2-l2 << '\n';
			j = kmp[j];
		}
	}
	for(int i=0;i<l2;i++)	cout << kmp[i]+1 << ' ';

	return 0;
}

