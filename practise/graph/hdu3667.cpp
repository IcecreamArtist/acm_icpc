#include<bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;

const int maxn = 102;
bitset<maxn> inq;
int d[maxn];
int p[maxn];
int a[maxn];
int head[maxn];

struct Edge {
    int from,to,cap,flow,cost,next;
}edges[maxn<<2];

int tot;

struct MCMF {
    int n,m;

    void init(int n){
        this->n = n;
        tot=0;
        memset(head,-1,sizeof(head));
    }

    void AddEdge(int from,int to,int cap,int cost){
        edges[tot++]=(Edge{from,to,cap,0,cost,head[from]});
        edges[tot++]=(Edge{to,from,0,0,-cost,head[to]});
        head[from]=tot-2;
        head[to]=tot-1;
    }

    int BellmanFord(int s,int t,int& flow,long long& cost,int k) {
        for(int i=0;i<n;++i) d[i]=inf;
        inq.reset();
        d[s] = 0;inq.set(s);p[s] = 0;a[s] = inf;

        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            inq.reset(u);
            for(int i=head[u];~i;i=edges[i].next){
                Edge& e = edges[i];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=i;  // 来的边的序号
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]) {Q.push(e.to);inq.set(e.to);}
                }
            }
        }
        if(d[t]==inf) return -1;
        if(flow + a[t] >= k) {
            cost += (long long)d[t] * (long long)(k-flow)*(k-flow);
            return false;
        }
        flow += a[t];
        cost += (long long)d[t] * (long long)a[t]*a[t];
        for(int u=t;u!=s;u=edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return true;
    }

    int MincostMaxflow(int s,int t,long long& cost,int k){
        int flow = 0;cost = 0;
        while(1){
            int tmp;
            tmp=BellmanFord(s,t,flow,cost,k);
            if(tmp==-1) return -1;
            if(tmp==0) return 0;
        };
    }
};

int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        MCMF cur;
        cur.init(n);
        for(int i=1;i<=m;++i){
            int u,v,w,c;
            scanf("%d%d%d%d",&u,&v,&w,&c);
            cur.AddEdge(u-1,v-1,c,w);
        }
        long long cost;
        int tmp=cur.MincostMaxflow(0,n-1,cost,k);
        if(tmp==-1) cout<<-1<<endl;
        else cout<<cost<<endl;
    }
}