#include<bits/stdc++.h>
using namespace std;
int a,b,c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> a >> b >> c;
    int t = c/(a+b),p = c%(a+b);
    cout << t*a+min(p,a);
    
    return 0;
}
