/*
 * 给一张连通无向图。q次加边，求每次加边之后的桥的数目。
 * 思路：题目的意思是要求在原图中加边后桥的数量，首先我们可以通过Tarjan求边双连通分量，对于边(u,v)，如果满足
low[v]>dfn[u],则为桥，这样我们就可以知道图中桥的数目了。对于每一次query,可以考虑dfs树，树边肯定是桥，然后连
上u,v这条边之后，就会形成一个环，这样环内的边就不是割边了，所以只要找到u,v的LCA,把这个路径上的桥标记为否就可以了。
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
int num[N],low[N],f[N],dfn,bridges,m,n,q,isbridge[N],mark[N];
vector<int>G[N]; // is bridge
void tarjan(int u,int fa){
    num[u] = low[u] = ++dfn;
    int first = 1;
    for(auto v:G[u]){
        if(v==fa&&first) {first = 0;continue;}  // multiple edges between two nodes
        if(!low[v]) f[v]=u,tarjan(v,u);
        low[u] = min(low[v],low[u]);
        if(low[v]>num[u]) {
            if(!isbridge[v]) bridges++;
            isbridge[v] = 1; // tree edge is bridge
        }
    }
}

void lca(int a,int b){
    while(num[a]>num[b]) {
        if(isbridge[a]) bridges--;
        isbridge[a] = 0,a=f[a];
    }
    while(num[b]>num[a]) {
        if(isbridge[b]) bridges--;
        isbridge[b] = 0,b=f[b];
    }
    while(a!=b) {
        if(isbridge[a]) bridges--;
        if(isbridge[b]) bridges--;
        isbridge[a] = isbridge[b] = 0;
        a=f[a],b=f[b];
    }
}
void init(){
    for(int i=1;i<=n;++i) isbridge[i]=low[i]=0,G[i].clear(),f[i]=i,mark[i]=0,num[i]=-1;
    bridges = 0,dfn = 0;
}
int main(){
    int c = 0;
    while(~scanf("%d%d",&n,&m),n||m){
        init();
        printf("Case %d:\n",++c);
        for(int i=1;i<=m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        tarjan(1,-1);  // any two computers are connected in the initial network
        scanf("%d",&q);
        while(q--){
            int a,b;scanf("%d%d",&a,&b);
            lca(a,b);
            printf("%d\n",bridges);
        }
        printf("\n");
    }
}