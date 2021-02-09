//
// Created by Artis on 2021/2/8.
//
#include<bits/stdc++.h>
using namespace std;
int ans;  // 最小
int n,k,m;
const int maxn = 103;
const int inf = 0x7f7f7f7f;
vector<int>G[maxn];
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
vector<Edge>edges;
bool done[maxn];
int d[maxn];
int p[maxn]; // 来到这个点的边的序号

void init(){
    for(int i=1;i<=n;++i) G[i].clear();
    edges.clear();
}

void AddEdge(int from,int to,int dist){
    edges.push_back(Edge{from,to,dist});
    m = edges.size();
    G[from].push_back(m-1);
}

struct HeapNode{
    int d,u;
    bool operator < (const HeapNode& rhs) const{
        return d>rhs.d;
    }
};

void dijkstra(int s){
    priority_queue<HeapNode>Q;
    for(int i=1;i<=n;++i) d[i]=inf;
    d[s]=0;
    memset(done,0,sizeof(done));
    Q.push((HeapNode){0,s});
    while(!Q.empty()){
        HeapNode x=Q.top();Q.pop();
        int u=x.u;
        if(done[u]) continue;
        done[u]=true;
        for(int i=0;i<G[u].size();++i){
            Edge& e = edges[G[u][i]];
            if(d[e.to]>d[u]+e.dist){
                d[e.to]=d[u]+e.dist;
                p[e.to]=G[u][i];
                Q.push((HeapNode){d[e.to],e.to});
            }
        }
    }
}


void dfs(int dis){
    dijkstra(1);
    if(dis>k) {ans=max(ans,d[n]);return;}
    int path[maxn],pp[maxn];
    for(int u=n;u!=1;u=edges[p[u]].from) {
        path[u] = edges[p[u]].from;
        pp[u]=p[u];
    }
    for(int u=n;u!=1;u=path[u]){
        int cur=edges[pp[u]].dist;
        edges[pp[u]].dist=inf;
        edges[pp[u]^1].dist=inf;
        dfs(dis+1);
        edges[pp[u]].dist=cur;
        edges[pp[u]^1].dist=cur;
    }
}

void solve(){
    scanf("%d%d",&n,&k);
    init();
    ans=0;
    for(int i=1;i<=n*(n-1)/2;++i){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        AddEdge(u,v,w);
        AddEdge(v,u,w);
    }
    dfs(1);
    cout<<ans<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}
