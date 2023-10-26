#include<bits/stdc++.h>
using namespace std;
int n,t,eat[100002],eaten[100002];
struct ele{
	int abi,age;
	bool operator <(const ele& other)const{
		return abi<other.abi || (abi==other.abi && age<other.age);
	}
};
set<ele> st;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	freopen("lions.in","r",stdin);
	freopen("lions.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t;
		st.insert({t,i});
	}
	for(int i=1;i<n;i++){
		auto minn = st.begin(),maxn = prev(st.end());
		st.erase(minn),st.erase(maxn);
		eaten[i] = minn -> age,eat[maxn -> age] = i;
		st.insert({maxn -> abi - minn -> abi,maxn -> age});
	}
	int tim;
	for(tim=n-1;tim>0;tim--){
		if(eat[eaten[tim]]){
			tim = eat[eaten[tim]];
		}else{
			break;
		}
	}
	sort(eaten+1,eaten+tim+1);
	cout << tim << '\n';
	for(int i=1;i<=tim;i++){
		cout << eaten[i] << ' ';
	}
	
	return 0;
}
