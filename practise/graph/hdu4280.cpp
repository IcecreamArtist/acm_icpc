#include<bits/stdc++.h>
using namespace std;
const int maxn = 100004;
const int inf = 0x7f7f7f7f;
vector<int>G[maxn];  // 放进ISAP会爆空间。。

struct ISAP {
    int n,m,s,t;
    struct Edge{
        int from,to,cap,flow;
    };
    vector<Edge> edges;
    void AddEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,cap,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int p[maxn];
    int num[maxn];
    int d[maxn];
    int cur[maxn];
    int BFS(){
        memset(d,-1,sizeof(d));
        queue<int>Q;
        Q.push(t);
        d[t]=0;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(d[e.to]==-1){
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return ~d[s];
    }
    // while循环实现dfs
    int Augment() {
        int x=t,a=inf;
        while(x!=s){
            Edge& e = edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s){
            edges[p[x]].flow += a;
            edges[p[x]^1].flow -= a;
            x=edges[p[x]].from;
        }
        return a;
    }
    int Maxflow(int s,int t){
        this->s=s,this->t=t;
        int flow=0;
        if(!BFS()) return 0;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;++i) num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n){
            // for 循环实现dfs
            if(x==t){
                flow += Augment();
                x=s;
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1) { // advance
                    ok=1;
                    p[e.to]=G[x][i];
                    cur[x]=i;
                    x=e.to;
                    break;
                }
            }
            if(!ok) { // retreat
                int mn=n-1;
                for(int i=0;i<G[x].size();++i){
                    Edge& e = edges[G[x][i]];
                    if(e.cap>e.flow) mn=min(mn,d[e.to]);
                }
                if(--num[d[x]]==0) break;  // gap
                num[d[x]=mn+1]++;
                cur[x]=0;
                if(x!=s) x=edges[p[x]].from;
            }
        }
        return flow;
    }
};

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    int minx=inf,idmin,idmax,maxx=-1;
    for(int i=1;i<=n;++i){
        int x,y;scanf("%d%d",&x,&y);
        if(x<minx) idmin=i,minx=x;
        if(x>maxx) idmax=i,maxx=x;
    }
    for(int i=1;i<=n;++i) G[i].clear();
    ISAP cur;
    cur.n=n;
    cur.s=idmin,cur.t=idmax;
    for(int i=1;i<=m;++i){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        cur.AddEdge(x,y,z);
    }
    printf("%d\n",cur.Maxflow(cur.s,cur.t));
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}