/*
 * 概念：图论中，满足两两之间有边连接的顶点的集合，被称为该无向图的团(clique)(complete graph)
 * 题意：给一个图，若有k完全图，输出2及其节点。若无k完全图而有每个点度数至少为k（这个度数指连接此点集内部的点）的点集
 * 输出1及点集的大小。若两者都无，输出-1
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int d[N],a[N]; // 度数
bool in[N];  // 判断一个点是否在集合中。O(1)的复杂度好过在st里面找
set<pair<int,int> >st; // 用来储存节点。前面是度数，后面是节点序号。按照度数排序
unordered_set<int> s[N]; //用来存边（便于查询、删除）
int main(){
    int t,n,m,k,sz;scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k),st.clear();
        for(int i=1;i<=n;++i) s[i].clear(),d[i]=0,in[i]=0,s[i].insert(i);
        for(int i=1;i<=m;++i) {
            int u,v;scanf("%d%d",&u,&v),s[u].insert(v),s[v].insert(u);
            d[u]++,d[v]++;
        }
        for(int i=1;i<=n;++i) st.insert(make_pair(d[i],i));
        while(!st.empty()) {
            int id = st.begin()->second;
            if(d[id]>=k) {
                printf("1 %d\n",st.size());
                for(auto nod:st) printf("%d ",nod.second);
                puts("");goto ed;
            }
            if(d[id]==k-1){
                sz = 0;
                for(auto v:s[id]) if(!in[v]) a[++sz] = v;
                for(int i=1;i<=sz;++i) for(int j=1;j<=sz;++j) if(!s[a[i]].count(a[j])) goto res3;
                printf("2\n");
                for(int i=1;i<=sz;++i) printf("%d ",a[i]);
                puts("");goto ed;
            }
            res3:
            in[id]=1,st.erase(st.begin());
            for(auto v:s[id]) if(!in[v])
                    st.erase(make_pair(d[v],v)),--d[v],st.insert(make_pair(d[v],v));
        }
        puts("-1");
        ed:;
    }
}