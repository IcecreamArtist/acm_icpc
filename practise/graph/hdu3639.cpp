#include<bits/stdc++.h>
using namespace std;
/*
 * 建反图。求sz。
 */

const int maxn = 5003;
int low[maxn],num[maxn],dfn,cnt,mx,sccno[maxn],in[maxn],id,sccn[maxn];
vector<int>G[maxn];
vector<int>G2[maxn];  // 反图
stack<int>s;

void dfs(int u){
    s.push(u);
    num[u]=low[u]=++dfn;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(!sccno[v])
            low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
        cnt++;
        while(1){
            int v=s.top();s.pop();
            sccno[v]=cnt;
            sccn[cnt]++;
            if(u==v) break;
        }
    }
}
int sup[maxn],vis[maxn],sm;
void dfs2(int u){
    vis[u]=1;
    sm+=sccn[u];
    for(int i=0;i<G2[u].size();++i){
        int v=G2[u][i];
        if(!vis[v]) dfs2(v);
    }
}

void init(int n){
    memset(num,0,sizeof(num));
    memset(sccno,0,sizeof(sccno));
    memset(in,0,sizeof(in));
    memset(sccn,0,sizeof(sccn));
    memset(sup,0,sizeof(sup));
    for(int i=1;i<=n;++i) G2[i].clear();
    for(int i=1;i<=n;++i) G[i].clear();
    dfn=cnt=mx=0;
}

void Tarjan(int n){
    for(int i=1;i<=n;++i) if(!num[i]) dfs(i);
    for(int i=1;i<=n;++i){
        for(int j=0;j<G[i].size();++j){
            int v=G[i][j];
            if(sccno[i]==sccno[v]) continue;
            G2[sccno[v]].push_back(sccno[i]);
            in[sccno[i]]++;
        }
    }
    for(int i=1;i<=cnt;++i) if(!in[i]) {
        sm=0;
        memset(vis,0,sizeof(vis));
        dfs2(i);
        sup[i]=sm-1;
        mx=max(mx,sup[i]);
    }

    cout<<"Case "<<++id<<": "<<mx<<endl;
    int isf=1;
    for(int i=1;i<=n;++i)
        if(sup[sccno[i]]==mx) {
            if(isf) cout<<i-1,isf=0;
            else cout<<" "<<i-1;
        }
    putchar(10);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        init(n);
        for(int i=1;i<=m;++i){
            int u,v;scanf("%d%d",&u,&v);
            G[++u].push_back(++v);
        }
        Tarjan(n);
    }
}

/*
 * 1
6 5
0 1
0 2
2 3
5 4
4 2
 */