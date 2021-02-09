#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
typedef long long ll;
const ll mod = 1e9+7;
int fa[maxn];
int a[maxn];
ll numc[maxn],numr[maxn];
ll hasr,hasc; // 有r的块的个数

void init(int n){
    hasr=hasc=0;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=n;++i) numc[i]=0;
    for(int i=1;i<=n;++i) numr[i]=0;
}

int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}

ll count_ccr(int x,int y){
    if((!numc[x])||(!numc[y])) return 0;
    ll newhasr=hasr;
    if(numr[x]) newhasr--;
    if(numr[y]) newhasr--;
    if(newhasr<=0) return 0;
    ll res=(numc[x]*numc[y]%mod*newhasr)%mod;
    return res;
}

ll count_ccc(int x,int y){
    if((!numc[x])||(!numc[y])) return 0;
    ll newhasc=hasc;
    if(numc[x]) newhasc--;
    if(numc[y]) newhasc--;
    if(newhasc<=0) return 0;
    ll res=(numc[x]*numc[y]%mod*newhasc)%mod;
    return res;
}

ll count_rcc(int x,int y){
    if((!numr[x])||(!numc[y])) return 0;
    ll newhasc=hasc;
    if(numc[x]) newhasc--;
    if(numc[y]) newhasc--;
    if(newhasc<=0) return 0;
    ll res=(numr[x]*numc[y]%mod*newhasc)%mod;
    return res;
}

ll ans;
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    ans=(ans-count_ccr(x,y)+mod)%mod;
    ans=(ans-count_ccc(x,y)+mod)%mod;
    ans=(ans-count_rcc(x,y)+mod)%mod;
    ans=(ans-count_rcc(y,x)+mod)%mod;
    numc[x]+=numc[y];
    numr[x]+=numr[y];
    if(numc[y]) hasc--;
    if(numr[y]) hasr--;
    fa[y]=x;
}

void solve(){
    int n;scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        if(a[i]==2) numc[i]++,hasc++;
        else numr[i]++,hasr++;
    }
    ans=0;
    if(hasc>=3) ans=hasc*(hasc-1)/2*(hasc-2)/3%mod;
    if(hasc>=2&&hasr!=0) ans=(ans+hasc*(hasc-1)/2*hasr%mod)%mod;

    for(int i=1;i<=n-1;++i){
        cout<<ans<<endl;
        int u,v;scanf("%d%d",&u,&v);
        unite(u,v);
    }
    cout<<ans<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}

