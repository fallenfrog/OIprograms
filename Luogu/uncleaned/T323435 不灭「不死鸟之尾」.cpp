#include<bits/stdc++.h>
using namespace std;
int n;
int w[100001],l[100001],r[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> w[i];
	for(int i=0;i<n;i++)
		cin >> l[i];
	for(int i=0;i<n;i++)
		cin >> r[i];
		
	int empty = n-1;
	long double tot = 0;
	for(int i=0;i<n;i++){
		tot += w[i]-max(l[i],r[i])*empty--;
	}
	printf("%.0Lf",tot);
	
	return 0;
}
