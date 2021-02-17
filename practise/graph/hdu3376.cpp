#include<bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
#define in(x) x
#define out(x) (x+n*n)
// 拆点 + 最大流
const int maxn = 604;
vector<int>G[maxn*maxn<<1];
int mp[maxn][maxn];
int inq[maxn*maxn<<1];
int d[maxn*maxn<<1];
int p[maxn*maxn<<1];
int a[maxn*maxn<<1];
struct Edge {
    int from,to,cap,flow,cost;
};

struct MCMF {
    int n,m;
    vector<Edge> edges;

    void init(int n){
        this->n = n;
        for(int i=0;i<n;++i) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap,int cost){
        edges.push_back(Edge{from,to,cap,0,cost});
        edges.push_back(Edge{to,from,0,0,-cost});
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
/*
 * 2
10 3
5 10
3
10 3 3
2 5 3
6 7 10
5
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9

 28
46
80
 */
int main(){
    int n;
    MCMF cur;
    while(~scanf("%d",&n)){
        cur.init(2*n*n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&mp[i][j]);
                //  cout<<out(n*(i-1)+j)<<" "<<in(n*i+j)<<endl;
                if(i!=0) cur.AddEdge(out(n*(i-1)+j),in(n*i+j),inf,0);
                if(j!=0) cur.AddEdge(out(n*i+j-1),in(n*i+j),1,0);
                cur.AddEdge(in(n*i+j),out(n*i+j),1,-mp[i][j]);
            }
        }
        long long cost;
        int s=out(0),t=in(n*n-1);
        cur.MincostMaxflow(s,t,cost);
        cout<<-cost+mp[0][0]+mp[n-1][n-1]<<endl;
    }
}