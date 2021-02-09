/*
 * 2-sat问题
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1003;
vector<int>G[maxn<<1];  // 原图
stack<int>s;
int low[maxn<<1],num[maxn<<1],sccno[maxn<<1],dfn,cnt;

void dfs(int u){
    low[u]=num[u]=++dfn;
    s.push(u);
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
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

bool Tarjan(int n){
    for(int i=0;i<n;++i)
        if(!num[i]) dfs(i);
    for(int i=0;i<n-1;i+=2)
        if(sccno[i]==sccno[i+1]) return 0;
    return 1;
}

void init(int n){
    for(int i=0;i<n;++i) G[i].clear();
    memset(num,0,sizeof(num));
    memset(sccno,0,sizeof(sccno));
    dfn=cnt=0;
}

int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        init(2*n);
        for(int i=1;i<=m;++i){
            int f1,f2,u,v;scanf("%d%d%d%d",&u,&v,&f1,&f2);
            G[u<<1|f1].push_back(v<<1|(f2^1));
            G[v<<1|f2].push_back(u<<1|(f1^1));
        }
        if(Tarjan(2*n)) puts("YES");
        else puts("NO");
    }
}
