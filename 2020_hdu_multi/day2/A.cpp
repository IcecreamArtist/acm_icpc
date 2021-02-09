# include <bits/stdc++.h>
# define pb push_back
# define ll long long
using namespace std;
const int maxn = 1e5+10;
vector<int> g[maxn];
bool in[maxn];
int r[maxn],b[maxn],fa[maxn];
int n,m;
int connect_num = 0;
int find(int x){
    return fa[x] = (x == fa[x] ? x : find(fa[x]));  //?
}
void comb(int x,int y){
    x = find(x); y = find(y);
    if(x != y){
        --connect_num;
        fa[x]=y;
    }
}

bool cmp(int x,int y){
    return b[x] > b[y];
}

void solve(){
    scanf("%d%d",&n,&m);
    connect_num = 0;
    for(int i=1;i<=n;++i) fa[i] = i; //Init Union-Find set
    for(int i=1;i<=n;++i) g[i].clear();
    for(int i=1;i<=n;++i) in[i] = false;
    for(int i=1;i<=n;++i) r[i] = i;

    for(int i=1;i<=n;++i) scanf("%d",&b[i]);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }

    sort(r+1,r+n+1,cmp);    //the ranking array from max to min

    ll ans = 0;
    in[r[1]] = true; ++ connect_num;
    for(int i=2;i<=n;++i){
        int u=r[i],ls=r[i-1];
        in[u] = true;
        ans += 1ll* (b[ls] - b[u]) * connect_num;
        ++connect_num;
        for(int j=0;j<g[u].size();++j){
            int v=g[u][j];
            if(in[v]) comb(v,u);
        }
    }
    ans += 1ll * b[r[n]] * connect_num;
    printf("%lld\n",ans);
}

int main(){
    int T; scanf("%d",&T);
    while(T--)solve();
    return 0;
}
