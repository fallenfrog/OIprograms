#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
stack<int> s;

int main(){
	cin >> n;
	for(int i=0;i<n;i++)	cin >> a[i];
	int j=0;
	for(int i=1;i<=n;i++){
		s.push(i);
		if(!s.empty() && s.top()==a[j]){
			while(!s.empty() && s.top()==a[j]){
				s.pop();j++;
			}	
		}
	}
	if(s.size())	cout << "NO";
	else	cout << "YES";
	
	return 0;
}
