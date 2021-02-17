#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+4;
typedef long long ll;
const ll mod = 1e9+7;
ll fa[maxn],numc[maxn],numr[maxn];
ll hasr,hasc;

void init(int n){
    hasr=hasc=0;
    for(int i=1;i<=n;++i) fa[i]=i,numc[i]=0,numr[i]=0;
}

int find(int x){
    return fa[x]=(fa[x]==x?x:find(fa[x]));
}

ll ans;
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    ans=(ans-numc[x]*numc[y]%mod*(hasr-numr[x]-numr[y]))%mod;
    ans=(ans-numc[x]*numc[y]%mod*(hasc-numc[x]-numc[y]))%mod;
    ans=(ans-numr[x]*numc[y]%mod*(hasc-numc[x]-numc[y]))%mod;
    ans=(ans-numc[x]*numr[y]%mod*(hasc-numc[x]-numc[y]))%mod;
    while(ans<0) ans+=mod;
    numc[x]+=numc[y];
    numr[x]+=numr[y];
    fa[y]=x;
}

void solve(){
    int n;scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;++i) {
        int u;
        scanf("%d",&u);
        if(u==2) numc[i]++,hasc++;
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

