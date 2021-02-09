//
// Created by Artis on 2021/1/25.
//
/*
 * 考虑一对1与0：即队长留下是1，队友留下是0.
 * 建图。接下来的关系是非此即彼的关系。
 * 先用一个map储存编号的对应关系。
 * 非此即彼：A->B', B->A'.
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3004;
int b[maxn];
vector<int>G[maxn];
stack<int>s;
int low[maxn],num[maxn],cnt,sccno[maxn],dfn;

void dfs(int u){
    num[u]=low[u]=++dfn;
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

void Tarjan(int n){
    for(int i=0;i<n;++i) if(!num[i]) dfs(i);
}

void init(int n){
    for(int i=0;i<n;++i) G[i].clear();
    memset(num,0,sizeof(num));
    memset(sccno,0,sizeof(sccno));
    dfn=cnt=0;
}

int main(){
    int t,m;
    while(~scanf("%d%d",&t,&m)){
        int cnt2=0;
        init(2*t);
        for(int i=1;i<=t;++i){
            int u,v,x;scanf("%d%d%d",&u,&v,&x);
            b[u]=cnt2++;  // 偶数点：队长
            b[v]=cnt2,b[x]=cnt2++; // 单数点：队员
        }
        int flg=0;
        for(int i=1;i<=m;++i){
            int u,v,ru,rv;scanf("%d%d",&u,&v);
            u=b[u],v=b[v],ru=(u&1)?u-1:u+1,rv=(v&1)?v-1:v+1;
            if(u==v){G[u].push_back(u-1);continue;}
            G[u].push_back(rv);
            G[v].push_back(ru);
        }
        Tarjan(2*t);
        for(int i=0;i<2*t;i+=2){
            if(sccno[i]==sccno[i+1]) {flg=1;break;}
        }
        if(flg) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}