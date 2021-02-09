//
// Created by Artis on 2021/2/2.
//
#include<bits/stdc++.h>
using namespace std;
/*
 * hdu 3549 最大流模板题
 */

const int maxn = 1002;
const int INF = 0x7f7f7f7f;

struct Dinic{
    int n,m,s,t;
    struct Edge{
        int from,to,cap,flow;
    };
    vector<Edge> edges;
    vector<int> G[maxn];

    void AddEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    };

    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    bool BFS() {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty()) {
            int x= Q.front();Q.pop();
            for(int i=0;i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow) {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x,int a){
        if(x==t||a==0) return a;
        int flow = 0,f;
        for(int& i=cur[x];i<G[x].size();++i){
            Edge& e = edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(BFS()){
            memset(cur,0,sizeof(cur));
            flow += DFS(s,INF);
        }
        return flow;
    }
};
int cas=0;
void solve(){
    Dinic cur;
    int n,m;cin>>n>>m;
    cur.n=n,cur.m=m;
    for(int i=1;i<=m;++i) {
        int x,y,c;scanf("%d%d%d",&x,&y,&c);
        cur.AddEdge(x,y,c);
    }
    printf("Case %d: %d\n",++cas,cur.Maxflow(1,n));
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}