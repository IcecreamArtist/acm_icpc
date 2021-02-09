/*
 * 最小点割+输出字典序最小的方案
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define in(x) x
#define out(x) (x+n)
using namespace std;
const int maxn = 403;
const int inf = 0x7f7f7f7f;
vector<int> G[maxn];
int A[maxn][maxn];
int isdel[maxn];

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
    void build(){
        edges.clear();
        for(int i=0;i<=2*n;++i) G[i].clear();
        for(int i=1;i<=n;++i)
            if(!isdel[i]) AddEdge(in(i),out(i),1);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(A[i][j]) AddEdge(out(i),in(j),inf);
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
        return d[s];
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
    int Maxflow(int s,int t){
        this->s=s,this->t=t;
        int flow=0;
        if(!BFS()) return 0;
        memset(num,0,sizeof(num));
        for(int i=1;i<=2*n;++i) num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<2*n){
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
                int mn=2*n-1;
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

int main(){
    int n,s,t;cin>>n>>s>>t;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&A[i][j]);
    if(A[s][t]) {cout<<"NO ANSWER!"<<endl;return 0;}
    ISAP cur;
    cur.n=n;
    cur.build();
    int ans=cur.Maxflow(out(s),in(t));
    cout<<ans<<endl;

    vector<int> res;
    for(int i=1;i<=n;++i){
        if(i==s) continue;
        if(i==t) continue;
        isdel[i]=1;
        cur.build();
        int newa = cur.Maxflow(out(s),in(t));
        if(newa==ans-1) res.push_back(i),ans--;
        else isdel[i]=0;
    }
    int sz=res.size();
    for(int i=0;i<sz-1;++i) cout<<res[i]<<" ";
    if(sz!=0) cout<<res[sz-1]<<endl;
}