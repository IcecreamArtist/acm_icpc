//
// Created by Artis on 2021/1/24.
//


# include <bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
# define pb push_back
using namespace std;
const int maxn = 1e5+10;
int n,k;
vector<int> g[maxn];
bool kx[maxn];   // 是否是字母
int tag[maxn];   // 子树中字母的个数
set<int> S;
void dfs(int x,int f){
    int cnt=0;
    for(int i=0;i<g[x].size();++i){
        int v=g[x][i];
        if(v != f){
            dfs(v,x);
            tag[x] += tag[v];
            if(tag[v]) cnt++;
        }
    }
    if(tag[x]!=k) cnt++;
    if(cnt>=2) S.insert(x);
}

int main(){
    scanf("%d%d",&n,&k);
    fo(i,1,n-1){
        int u,v,ww;
        scanf("%d%d%d",&u,&v,&ww);
        g[u].pb(v);
        g[v].pb(u);
    }
    fo(i,1,k){
        int cur;
        scanf("%d",&cur);
        kx[cur] = tag[cur] = 1;
        S.insert(cur);
    }
    dfs(1,-1);
    printf("%d\n",S.size());
    return 0;
}
