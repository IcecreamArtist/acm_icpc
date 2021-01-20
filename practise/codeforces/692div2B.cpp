#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 2520*18*1000 = 1e9

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

ll mul;

int test(ll n){
    ll nn = n;
    while(n){
        ll tmp = n%10;
        if(tmp==0) {n/=10;continue;}
        if(nn%tmp!=0) return 0;
        n/=10;
    }
    return 1;
}

void solve(){
    ll n;scanf("%lld",&n);
    for(int i=0;i<=mul;++i){
        //cout<<n+i<<endl;
        if(test(n+i)) {cout<<n+i<<endl;return;}
    }
}

int main(){
    int t;scanf("%d",&t);
    mul = 1;
    for(int i=1;i<=9;++i) mul = lcm(mul,i);
    while(t--) solve();
}

