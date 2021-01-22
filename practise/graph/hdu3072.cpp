//
// Created by Artis on 2021/1/21.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 50003;
vector<pair<int,int> >G[maxn];
int fee[maxn],cnt,dfn,low[maxn],num[maxn],sccno[maxn];
stack<int>s;

void dfs(int u){
    s.push(u);
    low[u]=num[u]=++dfn;
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i].first;
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
    memset(fee,0x7f7f7f7f,sizeof(fee));
    dfn=cnt=0;
    dfs(1);
    for(int i=1;i<=n;++i){
        for(int j=0;j<G[i].size();++j){
            int v=G[i][j].first,val=G[i][j].second;
            if(sccno[i]==sccno[v]) continue;
            fee[sccno[v]]=min(fee[sccno[v]],val);
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;++i) {
        if(i==sccno[1]) continue;
        ans+=fee[i];
    }
    cout<<ans<<endl;
}


int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;++i) G[i].clear();
        for(int i=1;i<=m;++i){
            int u,v,val;scanf("%d%d%d",&u,&v,&val);
            G[++u].push_back(make_pair(++v,val));
        }
        Tarjan(n);
    }
}
