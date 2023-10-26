#include<bits/stdc++.h>
using namespace std;
long long n;
unordered_map<long long,long long> d;

long long c(long long x){
	if(d[x]==0){
		d[x] = 1;
		for(int i=2;i<=sqrt(x);i++){
			if(x%i==0){
				d[x] += c(i);
				if(i*i!=x)
					d[x] += c(x/i);
			}
		}
	}
	return d[x];
}

int main(){
	cin >> n;
	cout << c(n);
	
	return 0;
}
