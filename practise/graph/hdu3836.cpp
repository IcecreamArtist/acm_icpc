#include<bits/stdc++.h>
using namespace std;
const int maxn = 20004;
int low[maxn],num[maxn],dfn,cnt,sccno[maxn],in[maxn],out[maxn];
stack<int>s;
vector<int>G[maxn];

void dfs(int u){
    s.push(u);
    num[u]=low[u]=++dfn;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(!num[v]){
            dfs(v);
            low[u]=min(low[v],low[u]);
        }else if(!sccno[v])
            low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u]){
        cnt++;
        while(1){
            int v=s.top();s.pop();
            sccno[v]=cnt;
            if(u==v) break;
        }
    }
}

void Tarjan(int n){
    memset(num,0,sizeof(num));
    memset(sccno,0,sizeof(sccno));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    dfn=cnt=0;
    for(int i=1;i<=n;++i)
        if(!num[i]) dfs(i);
    for(int i=1;i<=n;++i){
        for(int j=0;j<G[i].size();++j){
            int v=G[i][j];
            if(sccno[i]==sccno[v]) continue;
            in[sccno[v]]++;out[sccno[i]]++;
        }
    }
    int a1=0,a2=0;
    for(int i=1;i<=cnt;++i) {
        if(in[i]==0) a1++;
        if(out[i]==0) a2++;
    }
    if(cnt==1) cout<<0<<endl;
    else cout<<max(a1,a2)<<endl;
}
// max(入度=0的缩点个数,出度=0的缩点个数)

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;++i) G[i].clear();
        for(int i=1;i<=m;++i){
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        Tarjan(n);
    }
}