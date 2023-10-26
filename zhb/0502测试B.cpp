#include<bits/stdc++.h>
using namespace std;
int n,a[1002],k;
bool ntp[1002],app[1002];

void make_prime(){
	ntp[0] = ntp[1] = 1;
	for(int i=2;i<=sqrt(1000);i++){
		if(!ntp[i]){
			for(int j=2;j*i<=1000;j++){
				ntp[i*j] = 1;
			}
		}
	}
	ntp[1] = 0;
}

bool perfect(int x){
	int t = 1,k = x,m = sqrt(x);
	if(m*m==x)	t += m;
	for(int i=2;i<=m;i++){
		if(k%i==0){
			t += i;
			t += x/i;
		}
	}
	return t==x;
}

bool flower(int x){
	int t = 0,k = x;
	while(k>0){
		t += pow(k%10,3);
		k /= 10;
	}
	return t==x;
}

bool wave(int x){
	if(x<100)	return 0;
	return x/100==x%10 && x/100!=(x/10)%10;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	make_prime();
	cin >> n;
	int t;
	for(int i=0;i<n;i++){
		cin >> t;
		app[t] = 1;
	}
	sort(a,a+k);
	for(int i=1;i<1002;i++){
		if(app[i] && (!ntp[i] || perfect(i) || flower(i) || wave(i))){
			cout << i << ' ';
		}
	}
	
	return 0;
}
