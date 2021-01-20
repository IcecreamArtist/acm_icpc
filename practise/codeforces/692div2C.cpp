#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int fa[maxn];
int x[maxn],y[maxn];
int Find(int x){
    return fa[x]=fa[x]==x?x:Find(fa[x]);
}
void solve(){
    int n,m;scanf("%d%d",&n,&m);
    int ans = 0;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) continue;
        ans++;
        if(Find(x)==Find(y)) ans++;
        fa[Find(y)]=Find(x);   // in this way, at last we will only calculate once for a loop.
    }
    cout<<ans<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}

