#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct EdmondsKarp{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn]; //
    int p[maxn];
};