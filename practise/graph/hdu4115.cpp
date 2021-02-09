#include<bits/stdc++.h>
using namespace std;
/*
 * 这样考虑：
 * SAT问题都是解决1/0的问题的。
 * 正好，每轮Alice也只能在两个选项中选一个。那么其一算0，其二算1.
 * 限制条件：某和某一定一起选：如果A中有的B中无，那么有A'->A即不可选A，
 * 再有A'->B',B'->A'。
 * 如果都有，A->B,B->A,A'->B',B'->A'。
 * 某和某不可一起：如果A中有的B中无，不加边。
 * 再有A'->B,B->A'
 * 如果都有，A->B',B->A',A'->B,B'->A。
 */
const int maxn = 20003;
int a[maxn];
vector<int>G[maxn];
stack<int>s;
int num[maxn],low[maxn],dfn,cnt,sccno[maxn];
int b[maxn];  // 用来储存每个点分别是哪一号人物

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

void init(int n){
    for(int i=0;i<=n;++i) G[i].clear();
    memset(num,0,sizeof(num));
    memset(sccno,0,sizeof(sccno));
    dfn=cnt=0;
}

int main(){
    int t,cas=0;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        init(n<<1);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            if(a[i]==1) b[2*i]=2,b[2*i+1]=3;
            if(a[i]==2) b[2*i]=1,b[2*i+1]=3;
            if(a[i]==3) b[2*i]=1,b[2*i+1]=2;
        }
        for(int i=1;i<=m;++i){
            int u,v,opt;scanf("%d%d%d",&u,&v,&opt);
            u--,v--;
            if(opt){
                // 要两者不同。只需要让两者相同的那两个转向对方另一个。
                for(int j=2*u;j<=2*u+1;++j){
                    for(int k=2*v;k<=2*v+1;++k){
                        if(b[j]==b[k]){
                            G[j].push_back(k^1);
                            G[k].push_back(j^1);
                        }
                    }
                }
            }else{
                for(int j=2*u;j<=2*u+1;++j){
                    for(int k=2*v;k<=2*v+1;++k){
                        if(b[j]!=b[k]){
                            G[j].push_back(k^1);
                            G[k].push_back(j^1);
                        }
                    }
                }
            }
        }
        Tarjan(n<<1);
        int flg=0;
        for(int i=0;i<(n<<1);i+=2){
            if(sccno[i]==sccno[i+1]) {flg=1;break;}
        }
        cout<<"Case #"<<++cas<<": ";
        if(flg) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}