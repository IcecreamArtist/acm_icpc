/*
 * 题意：一个环，n个位置（从1开始），m条命令。从1出发，每个命令走wi步。顺时针逆时针的概率均等。求最后处于l与r之间的概率。
 * 概率 + 环形dp。
 * 这题是卡着时间过的。一定要用now^1来，不然两个数组相互赋值会TLE。
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,l,r;
double dp[2][204];
int main(){
    while(scanf("%d%d%d%d",&n,&m,&l,&r)==4){
        if(n==0&&m==0&&l==0&&r==0) break;
        for(int i=1;i<=n;++i) dp[0][i] = 0;
        dp[0][1] = 1;
        int now = 0;
        for(int i=1;i<=m;++i){
            int w;scanf("%d",&w);
            for(int j=1;j<=n;++j){
                dp[now^1][j] = 0.5*dp[now][(j-1-w+n)%n+1]+0.5*dp[now][(j-1+w)%n+1];
            }
            now^=1;
        }
        double ans=0;
        for(int i=l;i<=r;++i) ans+=dp[now][i];
        printf("%.4lf\n",ans);
    }
}