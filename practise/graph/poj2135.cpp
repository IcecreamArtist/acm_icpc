#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn = 1e3+4;
const int inf = 0x7f7f7f7f;
struct Edge {
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};

vector<int> G[maxn];

struct MCMF {
    int n,m;
    vector<Edge> edges;
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n){
        this->n = n;
        for(int i=0;i<n;++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap,int cost){
        edges.push_back(Edge{from,to,cap,0,cost});
        edges.push_back(Edge{to,from,cap,0,cost});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BellmanFord(int s,int t,int& flow,long long& cost) {
        for(int i=0;i<n;++i) d[i]=inf;
        memset(inq,0,sizeof(inq));
        d[s] = 0;inq[s] = 1;p[s] = 0;a[s] = inf;

        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();++i){
                Edge& e = edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]) {Q.push(e.to);inq[e.to]=1;}
                }
            }
        }
        if(d[t]==inf) return false;
        flow += a[t];
        cost += (long long)d[t] * (long long)a[t];
        for(int u=t;u!=s;u=edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return true;
    }

    int MincostMaxflow(int s,int t,long long& cost){
        int flow = 0;cost = 0;
        BellmanFord(s,t,flow,cost);
        BellmanFord(s,t,flow,cost);
        return flow;
    }
};

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    MCMF cur;
    cur.init(n);

    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        cur.AddEdge(u, v, 1, c);
    }

    long long cost;
    cur.MincostMaxflow(1, n, cost);
    cout << cost << endl;
}
