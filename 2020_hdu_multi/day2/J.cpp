//
// Created by Artis on 2021/2/1.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
typedef long long ll;
struct node{
    int a,b,c,d;
};
vector<node>type[maxn];
ll mx;int k;

void dfs(int u,ll sa,ll sb,ll sc,ll sd){
    if(u>=k) {
        ll dmg=sa*sb*sc*sd;
        mx=max(mx,dmg);
        return;
    }
    int sz=type[u+1].size();
    for(int i=0;i<sz;++i){
        node v=type[u+1][i];
        ll nsa=sa+v.a,nsb=sb+v.b,nsc=sc+v.c,nsd=sd+v.d;
        dfs(u+1,nsa,nsb,nsc,nsd);
    }
    dfs(u+1,sa,sb,sc,sd);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;scanf("%d%d",&n,&k);
        mx=0;
        for(int i=1;i<=n;++i) type[i].clear();
        for(int i=1;i<=n;++i){
            int tt,a,b,c,d;
            scanf("%d%d%d%d%d",&tt,&a,&b,&c,&d);
            type[tt].push_back({a,b,c,d});
        }
        dfs(0,100,100,100,100);
        cout<<mx<<endl;
    }
}
