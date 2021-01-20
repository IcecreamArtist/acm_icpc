/*
 * 数列分块模板题
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int N = 5e4+6;
ll a[N],b[N],s[N];
int id[N];

void add(int l,int r,ll x){
    int sid = id[l],eid = id[r];
    if(sid==eid){
        for(int i=l;i<=r;++i) a[i] += x, s[sid] += x;
        return;
    }
    for(int i=l;id[i]==sid;++i) a[i] += x,s[sid] += x;
    for(int i=sid+1;i<eid;++i) b[i] += x,s[i] += m*x;
    for(int i=r;id[i]==eid;--i) a[i] += x,s[eid] += x;
}

ll query(int l,int r,ll p){
    int sid = id[l], eid = id[r];
    ll ans = 0;
    if(sid==eid){
        for(int i=l;i<=r;++i) ans = (ans + a[i] + b[sid])%p;
        return ans;
    }
    for(int i=l;id[i]==sid;++i) ans = (ans + a[i] + b[sid])%p;
    for(int i=sid+1;i<eid;++i) ans = (ans + s[i])%p;
    for(int i=r;id[i]==eid;--i) ans = (ans + a[i] + b[eid])%p;
    return ans;
}

int main(){
    scanf("%d",&n);
    m = (int)sqrt(n+0.1);
    for(int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
        id[i] = (i-1)/m + 1;
        cout<<"id == "<<id[i]<<endl;
        s[id[i]] += a[i];
    }
    int opt,l,r,c;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d%d",&opt,&l,&r,&c);
        if(opt) printf("%lld\n",query(l,r,c+1));
        else add(l,r,c);
    }
}