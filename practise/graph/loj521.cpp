/*
 * 题意：n个点的一棵树，每个点相连点中点权最小的那个点是这个点的“庇护所”，要求任意两点“庇护所”不同。
 * 要求输出字典序最小点权。
 * 合法：注意到，叶子结点只能指向其父亲。（如果一个节点有两个或以上叶子，-1）
 * 为了尽可能合法，我们让父亲也指向该叶子节点。那么这一块就可以脱出。最后要达到合法，所有节点都尽可能两两一组。
 * 因此，判断合法性只需判断是否可以做到让所有【相邻】节点都两两一组。
 * 大概答案也是只能够相邻两两一组了（暴论）
 * 那就，交给dfs8
 * 如何实现？【重点】
 * 直接模拟得出**不等式关系**后，拓扑排序，用堆维护当前度为0的点。
 * 不等式关系即：1与2的关系若成立，必须有1是2的父亲以及其他son之中最小的。把这种不等式关系转化为图（即to），计算度数
 * 就可以通过拓扑排序求出结果。
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N],n;
vector<int>G[N];
vector<int>to[N]; // topo, stores nodes that are greater than it.
int d[N],ans[N],p[N],in[N];
// p==1: bottom one; ==0:havent been there; ==2:upper one p:position
bool flg = 0;            //               if it is unable to get pair

void dfs(int u,int fa){
    int tt = 0;
    for(auto v:G[u]){
        if(v==fa) continue;
        dfs(v,u);
        if(p[v]==1){
            if(p[u]==2) flg = 1;// that is, this node need to get pair with more than one son
            p[u] = 2,tt = v; // if its child is 1, this node must be 2
        }
    }
    if(p[u]==0){  // if is unset, it is the bottom one, it needs to get pair with its father.
        // and its father needs to get pair with it.
        // therefore, its father needs to be the lowest one among its children
        p[u]=1;
        for(auto v:G[u]){
            if(v==fa) continue;
            to[fa].push_back(v);in[v]++;
        }
    }else{
        // else, this node is the upper one, it needs to get pair with its son tt. tt is set before.
        // therefore, tt needs to be the lowest one among this node's children.
        for(auto v:G[u]){
            if(v==tt) continue;
            to[tt].push_back(v);in[v]++;
        }
    }
}
priority_queue<int,vector<int>,greater<int> >q;
// 优先队列，使得序列字典序最小。
// 拓扑排序
void toposort(){
    for(int i=1;i<=n;++i) if(!in[i]) q.push(i);
    for(int i=1;i<=n;++i) {
        if(!q.size()) {flg=1;break;}
        int u=q.top();q.pop();
        ans[i]=u;
        for(auto v:G[u]){
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i) {
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);     // 答主用邻接表存边
        ++d[u],++d[v];
    }
    dfs(1,-1);
    toposort();
    if(flg) puts("-1");
    else for(int i=1;i<=n;++i) printf("%d ",ans[i]);
}