/*
 * https://codeforces.com/contest/1455/problem/G
 * 好题，还没有完全搞懂，慢慢咀嚼
 * 题意：花费最少，防止x被设为s。
 * dp[i][j]直到第i句，x==j
 * 从前往后更新，
 * 遇到if
 * if("if"&&j==a) {
 *     dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
 *     dp[end+1][j] = min(dp[end+1][j],dp[i][j]+v);
 * }
 * 遇到set
 * if(y==s) dp[i+1][j] = min(dp[i+1][j],dp[i][j]+v);
 * else {
 *     dp[i+1][j] = min(dp[i+1][j],dp[i][j]+v);
 *     dp[i+1][y] = min(dp[i+1][y],dp[i][j]);
 * }
 * 遇到end,dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
 * 只不过j的范围是2e5。会TLE。此时可能需要借助数据结构。
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q,s;
char buf[10];

struct St{
    St(int be){mp[be]=0;g[0]=1;}
    void set(int v,ll c){
        base+=c;                                             //   base means if we spend money in each set operation, the total cost
        if(v==s) return;
        add(v,mi()-c);                                    //   if we do not spend the money, we choose to change. we go from the minimum cost before
    }
    void add(int v,ll c){                                    //   dp update, choose the cheapest cost for the y v and store.
        if(mp.count(v)){
            if(mp[v]+base<=c) return;                        //   if the total value of original v is cheaper, change nothing
            del(v);                                          //   otherwise, delete the original v
        }
        c-=base;                                             //   get the value of v under current base
        mp[v]=c;                                             //   assign new v
        g[c]++;                                              //   this cost increase by 1
    }
    ll mi(){return g.begin()->first+base;}                   //   the minimum of cost after operations plus current base
    bool has(int x){return mp.count(x);}
    void del(int x){
        ll c=mp[x];
        if(g[c]==1) g.erase(c);
        else g[c]--;
        mp.erase(x);                                         //   delete the record inside g and mp.
    }
    ll base=0;
    map<int,ll> mp;                                          //   restore the minimum cost of each y currently
    map<ll,int> g;                                           //   serve as a heap, to store the possible answers and restore the minimum one
};

void merge(St& a, St& b){
    if(a.mp.size()<b.mp.size()) swap(a,b);            //   small-to-large, optimise the time complexity
    for(const auto& i:b.mp){
        int v=i.first;
        a.add(v,i.second+b.base);                         //   update the map of v inside a, remember to add the base of b
    }
}

St f(int be){
    St st(be);
    while(q--){
        scanf("%s",buf);
        int v,c;
        switch(buf[0]){
            case 's':
                scanf("%d%d",&v,&c);
                st.set(v,c);
                break;
            case 'i':
            {
                scanf("%d",&v);
                St tt=f(v);
                if(st.has(v)){                                //    如果st中,v没出现过,那必不可能进入这个if语句.
                    tt.base+=st.mp[v]+st.base;                //    tt的基础得在st中抵达v的最少花费与st的基础的和之上
                    st.del(v);                                //    st中的v在这里必须被if使用,原状态就要被删除
                    merge(st, tt);                     //    把tt的结果更新到st中
                }
            }
                break;
            case 'e':
                return st;
            default:
                exit(1);
        }
    }
    return st;
}

int main() {
    scanf("%d%d",&q,&s);
    St st=f(0);
    printf("%lld\n",st.mi());
    return 0;
}
