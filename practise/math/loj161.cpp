/*
 * 给定n个正整数ai，求每个数在模p下的乘法逆元
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+7;
const int P = 1e9+7;
typedef long long ll;
ll a[N],s[N],sv[N],inv[N];

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

int qpow(ll a,int n){
    int ans = 1;
    while(n){
        if(n&1) ans=ans*a%P;
        a=a*a%P;
        n>>=1;
    }
    return ans;
}

void solve(int n){
    s[0] = 1;
    for(int i=1;i<=n;++i) s[i] = s[i-1]*a[i]%P;
    sv[n] = qpow(s[n],P-2);
    for(int i=n;i>=1;--i) sv[i-1] = sv[i]*a[i]%P;
    for(int i=1;i<=n;++i) inv[i] = sv[i]*s[i-1]%P;
}

int main(){
    int n=read();
    for(int i=1;i<=n;++i) a[i] = read();
    solve(n);
    ll ans = 0;
    ll pro = qpow(998244353,n);
    ll invpro = qpow(998244353,P-2);
    for(int i=1;i<=n;++i) pro=(pro*invpro)%P,ans = (ans+(long long)inv[i]*pro%P)%P;
    cout<<ans<<endl;
}