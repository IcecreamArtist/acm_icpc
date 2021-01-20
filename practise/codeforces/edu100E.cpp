#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >G;
const int maxn = 3e5+5;
int fa[maxn],in[maxn],pos[maxn],nex[maxn];
vector<int> a;  // tree edge
vector<int> ans;

int find(int x){
    return fa[x]=fa[x]==x?x:find(fa[x]);
}

void unite(int x,int y){
    x = find(x),y = find(y);
    if(x==y) return;
    fa[y] = x;
}

// bfs implementation
void bfs(int x){
    queue<int> q;
    q.push(x);
    ans.push_back(x);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto v:G[u]){
            if(!(--in[v])){
                q.push(v);
                ans.push_back(v);
            }
        }
    }
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int rt = 0;
    G.resize(n+1);
    for(int i=1;i<=n;++i){
        int x;scanf("%d",&x);
        fa[i] = i;
        if(x==0) rt = i;
        a.push_back(x);
    }
    for(int i=1;i<=m;++i){
        int x,y;scanf("%d%d",&x,&y);
        nex[x] = y;
        unite(x,y);
    }
    for(int i=1;i<=n;++i){
        int x = find(a[i-1]),y = find(i);
        if(x==y) continue;
        G[x].push_back(y);
        in[y]++;
    }
    int cnt = 0; // number of component
    for(int i=1;i<=n;++i) if(i==find(i)) cnt++;
    rt = find(rt);
    bfs(rt);
    vector<int> res;
    for(auto u:ans){
        for(int j=u;j;j=nex[j]){
            res.push_back(j);
            if(res.size()>n) {puts("0");return 0;}
        }
    }
    for(int i=0;i<res.size();++i) pos[res[i]] = i;
    for(int i=1;i<=n;++i) {
        int x = a[i-1],y = i;
        if(x==0) continue;
        if(pos[x] >= pos[y]){
            puts("0");return 0;
        }
    }
    for(auto i:res) cout<<i<<" ";
    cout<<endl;
}