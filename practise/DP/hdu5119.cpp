/*
 * 题意：一个数组，选其中任意个，异或和大于等于m的选择方法数。
 * 思路：每个数有选与不选两种方案：01背包。
 */
#include <bits/stdc++.h>
using namespace std;
int n,m,t;
const int N = 1e6+4;
int a[44],dp[2][N<<2];
int main(){
    scanf("%d",&t);
    int c = 0;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int i=0;i<(N<<1);++i) dp[0][i] = 0,dp[1][i] = 0;
        dp[0][0] = 1;
        int now=0;
        for(int i=1;i<=n;++i) {
            for(int j=0;j<(N<<1);++j)
                dp[now^1][j] = dp[now][j] + dp[now][j^a[i]];
            now^=1;
        }
        long long ans = 0;
        for(int i=m;i<(N<<2);++i) ans += dp[now][i];
        printf("Case #%d: %lld\n",++c,ans);
    }
}