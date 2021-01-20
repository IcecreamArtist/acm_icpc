/*
 * 求解：(x\times 2^m)%(n+1)=L的x。用exgcd
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll mul(ll a,ll b,ll p){  // 大数乘（防止乘的时候爆ll）
    ll ans = 0;
    while(b){
        if(b&1) ans = (ans+a)%p;
        a = (a+a)%p;
        b>>=1;
    }
    return ans;
}

ll qpow(ll a,ll n,ll p){
    ll ans = 1;
    while(n){if(n&1) ans=mul(ans,a,p);a=mul(a,a,p);n>>=1;}
    return ans;
}

inline ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b) {x=1,y=0;return a;}
    ll g = exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return g;
}

int main(){
    ll n,m,l;scanf("%lld%lld%lld",&n,&m,&l);
    ll x,y;
    ll m2 = qpow(2,m,n+1);
    ll g = exgcd(m2,n+1,x,y);
    x=(x%(n+1)+n+1)%(n+1);
    x = mul(x,l/g,n+1);
    cout<<x<<endl;
}
