#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+6;
ll a[maxn],b[maxn];

inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll mul(ll a,ll b,ll p){
    ll ans = 0;
    while(b){
        //cout<<b<<endl;
        if(b&1) ans=(ans+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return ans;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    ll g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

int n;
ll excrt(){
    ll m1=a[1],r1=b[1];
    ll x,y;
    for(int i=2;i<=n;++i){
        ll m2=a[i],r2=b[i];
        ll c = (r2-r1%m2+m2)%m2;
        ll g = exgcd(m1,m2,x,y);
        if(c%g) return -1;
        ll l = m1/g*m2;
        x=mul(x,c/g,m2/g);
        r1=((r1+x*m1)%l+l)%l;
        m1=l;
        //cout<<"r1 == "<<r1<<" m1 == "<<m1<<endl;
    }
    return r1;
}

int main(){
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),b[i]=read();
    cout<<excrt()<<endl;
}