/*
 * 二进制压缩爆搜
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 504;
const int maxm = 18;
char s[maxn];
bitset<maxn> p[maxm];
// 空间为1bit

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            scanf("%s",s+1);
            p[i].reset();
            for(int j=1;j<=n;++j) if(s[j]=='1') p[i].set(j);
        }
        int base = (1<<m)-1,ans=20;
        // all possible situations
        for(int i=0;i<=base;++i){
            bitset<maxn> cnt;
            int k=0;
            // for each element, if it is inside
            for(int j=0;j<m;++j){
                if(i&(1<<j)) cnt|=p[j+1],k++;
                if((int)cnt.count()==n) ans = min(ans,k);
            }
        }
        if(ans==20) printf("-1\n");
        else printf("%d\n",ans);
    }
}