/*
 * 混合图的欧拉回路
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 204;
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
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int p[maxn];
    int num[maxn];
    int d[maxn];
    int vis[maxn];
    int cur[maxn];
    int BFS(){
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        queue<int>Q;
        Q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]){
                    d[e.to]=d[x]+1;
                    vis[e.to]=1;
                    Q.push(e.to);
                }
            }
        }
        return ~d[s];
    }
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
    int Maxflow(){
        int flow=0;
        if(!BFS()) return 0;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;++i) num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n){
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
int degree[maxn];
void solve(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n+2;++i) G[i].clear();
    memset(degree,0,sizeof(degree));
    ISAP cur;cur.n=n+2,cur.s=1,cur.t=n+2;
    for(int i=1;i<=m;++i){
        int u,v,opt;scanf("%d%d%d",&u,&v,&opt);
        degree[++v]--;
        degree[++u]++;
        if(opt!=1) cur.AddEdge(u,v,1);
    }
    int sum=0;
    for(int i=2;i<=n+1;++i){
        if(abs(degree[i])&1) {cout<<"impossible"<<endl;return;}
        if(degree[i]>0) {
            cur.AddEdge(1,i,degree[i]/2);
            sum+=degree[i]/2;
        }
        if(degree[i]<0) cur.AddEdge(i,n+2,-degree[i]/2);
    }
    if(sum==cur.Maxflow()) cout<<"possible"<<endl;
    else cout<<"impossible"<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}