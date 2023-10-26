#include<bits/stdc++.h>
using namespace std;
int n,prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int cnt[25];
bool flag;

int main(){
	cin >> n;
	for(int i=0;i<25;i++){
		while(n%prime[i]==0){
			n /= prime[i];
			cnt[i]++;
		}
		if(cnt[i]>0){
			if(flag)	cout << '*';
			cout << prime[i];
			flag = 1;
			if(cnt[i]>1){
				cout << '^' << cnt[i];
			}
		}
	}
	
	return 0;
}
