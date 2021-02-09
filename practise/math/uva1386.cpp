#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,d,k;
const int N = 504;

struct mat{
    ll v[N];
    mat() {memset(v,0,sizeof(v));}
    inline mat operator *(mat c) const{
        mat ans;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                ans.v[i]=(ans.v[i]+v[j]*c.v[(i-j+n)%n])%m;
        return ans;
    }
};

mat qpow(mat x,ll k){
    if(k==1) return x;
    mat tmp=x*x;
    mat res=qpow(tmp,k>>1);
    if(k&1) res=res*x;
    return res;
}

int b[N];

int main(){
    while(~scanf("%lld%lld%lld%lld",&n,&m,&d,&k)){
        mat a;
        for(int i=0;i<=d;++i) a.v[i]=1;
        for(int i=n-1;i>=n-d;--i) a.v[i]=1;
        a=qpow(a,k);
        for(int i=0;i<n;++i) scanf("%lld",&b[i]);
        for(int i=0;i<n;++i){
            ll ans=0;
            for(int j=0;j<n;++j)
                ans=(ans+b[j]*a.v[(j-i+n)%n])%m;
            printf("%lld%c",ans,(i==n-1?'\n':' '));
        }
    }
}
