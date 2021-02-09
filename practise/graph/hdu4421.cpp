//
// Created by Artis on 2021/1/26.
//
#include<bits/stdc++.h>
using namespace std;
/*
 * 500*62个点。直接MLE了(。
 */
const int maxn = 503*2;
vector<int>G[maxn];
int num[maxn],low[maxn],sccno[maxn],dfn,cnt;
stack<int>s;
void init(int n){
    for(int i=0;i<n;++i) G[i].clear();
    memset(num,0,sizeof(num));
    memset(sccno,0,sizeof(sccno));
    dfn=cnt=0;
}

void dfs(int u){
    num[u]=low[u]=++dfn;
    s.push(u);
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(!num[v]){
            dfs(v);
            low[u]=min(low[v],low[u]);
        }else if(!sccno[v])
            low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
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

int b[maxn][maxn];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            scanf("%d",&b[i][j]);
        int flg=1;
        for(int i=0;i<n&&flg;++i){
            if(b[i][i]!=0) flg=0;
            for(int j=i+1;j<n&&flg;++j)
                if(b[i][j]!=b[j][i]) flg=0;
        }
        if(!flg){cout<<"NO"<<endl;continue;}
        for(int k=0;k<31&&flg;++k){
            init(n<<1);
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    int is1=b[i][j]&(1<<k);
                    int u=2*i,v=2*j;
                    if((i%2)&&(j%2)){
                        if(is1){
                            G[u].push_back(v^1);
                            G[v].push_back(u^1);
                        }else{
                            G[u^1].push_back(u);
                            G[v^1].push_back(v);
                        }
                    }else if(!(i%2)&&!(j%2)){
                        if(is1){
                            G[u].push_back(u^1);
                            G[v].push_back(v^1);
                        }else{
                            G[u^1].push_back(v);
                            G[v^1].push_back(u);
                        }
                    }else{
                        if(is1){
                            G[u].push_back(v^1);
                            G[v].push_back(u^1);
                            G[u^1].push_back(v);
                            G[v^1].push_back(u);
                        }else{
                            G[u^1].push_back(v^1);
                            G[v^1].push_back(u^1);
                            G[u].push_back(v);
                            G[v].push_back(u);
                        }
                    }
                }
            }
            Tarjan(n<<1);
            for(int i=0;i<(n<<1);i+=2){
                if(sccno[i]==sccno[i+1]) {flg=0;break;}
            }
        }
        if(!flg) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
