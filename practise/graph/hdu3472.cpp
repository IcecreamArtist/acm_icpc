/*
 * 欧拉路。有无向边也有有向边：混合图。
 * 两个点奇数度。度：出度-入度。想办法让他们度数变为1.其他点度数为0
 * 同样的，删剩无向边。
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int inf = 0x7f7f7f7f;
vector<int>G[maxn];

struct DSU {
    int fa[maxn],vis[maxn];
    void init(int n){
        for(int i=1;i<=n;++i) fa[i]=i;
        memset(vis,0,sizeof(vis));
    }
    int find(int x){
        return fa[x]=(fa[x]==x?x:find(fa[x]));
    }
    void unite(int x,int y){
        vis[x]=vis[y]=1;
        x=find(x),y=find(y);
        if(x==y) return;
        fa[x]=y;
    }
    int num(int n){
        int cnt=0;
        for(int i=1;i<=n;++i)
            if(vis[i]&&fa[i]==i) cnt++;
        return cnt;
    }
};

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
    int mp[maxn];
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
        n=1;
        mp[n]=t;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();++i){
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]){
                    ++n;
                    vis[e.to]=1;
                    mp[n]=e.to;
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
        for(int i=1;i<=n;++i) num[d[mp[i]]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n){
          //  cout<<d[s]<<endl;
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
};

int degree[maxn];
int cas;
void solve(){
    int n;cin>>n;
    ISAP cur;DSU cur2;
    cur2.init(28);
    memset(degree,0,sizeof(degree));
    for(int i=1;i<=28;++i) G[i].clear();
    for(int i=1;i<=n;++i){
        int opt;string s;cin>>s;
        int u=s[0]-'a'+1,v=s[s.length()-1]-'a'+1;
        scanf("%d",&opt);
        degree[++u]++;
        degree[++v]--;
        cur2.unite(u,v);
        if(opt) cur.Addedge(u,v,1);
    }
    cout<<"Case "<<++cas<<": ";
    if(cur2.num(28)!=1) {cout<<"Poor boy!"<<endl;return;}
    int sum=0,s=inf,t=inf,count=0;
    for(int i=2;i<=27;++i){
        if(abs(degree[i])&1){
            if(count==0) s=i;
            else t=i;
            count++;
        }
        if(degree[i]>0) {
            cur.Addedge(1,i,degree[i]/2);
            sum+=degree[i]/2;
        }
        if(degree[i]<0)
            cur.Addedge(i,28,-degree[i]/2);
    }
    if(count!=2&&count!=0) {cout<<"Poor boy!"<<endl;return;}
    if(s!=inf&&t!=inf) {
        if (degree[s] < degree[t]) swap(s, t);
        cur.Addedge(t,s,1);
    }
    if(sum==cur.Maxflow(1,28)) cout<<"Well done!"<<endl;
    else cout<<"Poor boy!"<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}
