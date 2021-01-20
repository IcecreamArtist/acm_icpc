/*
 * 求C(n,n-m)*D_{n-m}%1e9+7
 */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+7;
const int MOD = 1e9+7;
ll fac[N],invfac[N],s[N],sv[N];
ll D[N];

inline ll mul(ll a,ll b){
    ll ans = 0;
    while(b){
        if(b&1) ans=(ans+a)%MOD;
        a = (a+a)%MOD;
        b>>=1;
    }
    return ans;
}

inline ll qpow(ll a,ll n){
    ll ans = 1;
    while(n){
        if(n&1) ans=mul(ans,a);
        a=mul(a,a);
        n>>=1;
    }
    return ans;
}

int main(){
    int t;scanf("%d",&t);
    int n,m;
    D[0]=1,D[1]=0,D[2]=1;
    for(int i=3;i<N-4;++i) D[i] = mul(i-1,(D[i-1]+D[i-2])%MOD);
    fac[0]=1,fac[1] = 1;
    invfac[0]=1;
    for(int i=2;i<N-4;++i) fac[i] = mul(fac[i-1],i);
    s[0] = 1;
    for(int i=1;i<N-4;++i) s[i] = mul(s[i-1],fac[i]);
    sv[N-5] = qpow(s[N-5],MOD-2);
    for(int i=N-5;i>=1;--i) sv[i-1] = mul(sv[i],fac[i]);
    for(int i=1;i<N-4;++i) invfac[i] = mul(sv[i],s[i-1]);

    //for(int i=1;i<N-4;++i) cout<<fac[i]<<" ";
    //cout<<endl;
    //for(int i=1;i<N-4;++i) cout<<invfac[i]<<" ";
    //cout<<endl;
    //for(int i=1;i<N-4;++i) cout<<D[i]<<" ";
    //cout<<endl;
    while(t--){
        scanf("%d%d",&n,&m);
        ll ans = mul(D[n-m],fac[n]);
        ans = mul(ans,invfac[n-m]);
        ans = mul(ans,invfac[m]);
        printf("%lld\n",ans);
    }
}
