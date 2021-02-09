//
// Created by Artis on 2021/2/4.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
const int inf = 0x7f7f7f7f;
vector<int> G[maxn];
int is[maxn];
struct ISAP {
    int n,m,s,t;
    struct Edge{
        int from,to,cap,flow;
    };
    vector<Edge> edges;
    void Addedge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int p[maxn];
    int num[maxn];
    int d[maxn];
    int cur[maxn];
    int vis[maxn];
    int BFS(){
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));
        queue<int> Q;
        Q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return d[s];
    }
    int Augment(){
        int x=t,a=inf;
        while(x!=s){
            Edge& e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s){
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;
            x=edges[p[x]].from;
        }
        return a;
    }
    int Maxflow(int s,int t){
        this->s=s,this->t=t;
        int flow=0;
        if(!BFS()) return 0;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;++i) num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n){
            if(x==t) flow+=Augment(),x=s;
            int ok=0;
            for(int i=cur[x];i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1) {
                    ok=1;
                    p[e.to]=G[x][i];
                    cur[x]=i;
                    x=e.to;
                    break;
                }
            }
            if(!ok){
                int mn=n-1;
                for(int i=0;i<G[x].size();++i){
                    Edge& e=edges[G[x][i]];
                    if(e.cap>e.flow) mn=min(mn,d[e.to]);
                }
                if(--num[d[x]]==0) break;
                num[d[x]=mn+1]++;
                cur[x]=0;
                if(x!=s) x=edges[p[x]].from;
            }
        }
        return flow;
    }
    void getedge(){
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        queue<int> Q;
        Q.push(1);
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    Q.push(e.to);
                }
            }
        }
        vector<int> ed;
        for(int i=0;i<m;i+=2){
            if(edges[i].to!=t&&vis[edges[i].from]&&!vis[edges[i].to])
                ed.push_back(i/2+1);
        }
        cout<<ed.size()<<" ";
        for(int i=0;i<ed.size()-1;++i) cout<<ed[i]<<" ";
        cout<<ed[ed.size()-1]<<endl;
    }
};
int cas=0;
void solve(){
    int n,m,f;cin>>n>>m>>f;
    ISAP cur;cur.n=n+1;
    for(int i=1;i<=n+1;++i) G[i].clear();
    memset(is,0,sizeof(is));
    for(int i=1;i<=m;++i){
        int u,v,c;scanf("%d%d%d",&u,&v,&c);
        cur.Addedge(u,v,c);
    }
    int sum=0;
    for(int i=1;i<=f;++i){
        int u,c;scanf("%d%d",&u,&c);
        is[u]=1;
        sum+=c;
        cur.Addedge(u,n+1,c);
    }
    int mincut=cur.Maxflow(1,n+1);
    cout<<"Case "<<++cas<<": "<<sum-mincut<<endl;
    // 删了哪些边？
    // 最小割把图分成两部分。走残留网络中cap>flow的边，我们能到达s图
    // 剩下的点在t图中。对于s图中每个点的每条边，判断其是否连向t图。
    // 如是，print。
    cur.getedge();
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}
