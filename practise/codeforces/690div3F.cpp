#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int a[200005];
ll fac[200003],invfac[200003],s[200003],sv[200003];

ll qpow(ll a,ll n){
    ll ans =1;
    while(n){
        if(n&1) ans=(ans*a)%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return ans;
}

void init(){
    fac[1]=fac[0]=1;
    for(int i=2;i<200003;++i) fac[i]=(fac[i-1]*i)%MOD;
    s[0] = 1;
    invfac[0] = 1;
    for (int i = 1; i <200003; ++i) s[i] = s[i - 1] * fac[i] % MOD;
    sv[200002] = qpow(s[200002], MOD - 2);
    for (int i = 200002; i >= 1; --i) sv[i - 1] = sv[i] * fac[i] % MOD;
    for (int i = 1; i <200003; ++i) invfac[i] = sv[i] * s[i - 1] % MOD;
}


ll C(int a,int b){
    return fac[a]*invfac[b]%MOD*invfac[a-b]%MOD;
}

int main(){
    int t;scanf("%d",&t);
    init();
    while(t--){
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        ll ans = 0;
        int pos=1;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;++i){
            int val = a[i]-k;
            while(a[pos]<val){
                pos++;
            }
            //cout<<i-pos<<" "<<m-1<<endl;
            ll tmp=0;
            if(i-pos>=m-1) tmp=C(i-pos,m-1);
            ans=(ans+tmp)%MOD;
        }
        cout<<ans<<endl;
    }
}
