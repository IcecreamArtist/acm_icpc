/*
 * 题意：一个数组，有正数有负数。分成连续的m个子段，要求这m个子段的总和最大，求这个和。
 * 例如：-1 4 -2 3 -2 3，划分为一段(m==1)：取 4 -2 3 -2 3这一段最佳：得到8
 * 思路：dp。状态：dp[i][j]，遍历到第j个数字，已经分出了i个段。且选择当前数字。得到的最大和
 * 状态转移：dp[i][j] = max(dp[i][j-1]+a[i],max(dp[i-1][k]+a[i])); (i-1<=k<=j-1)
 *                       当前数字分到上一段中       当前数字新开一段，上一段末尾数字位置任意
 * 观察这个状态转移，有三重循环。而第三重循环从dp[i-1][i-1]到dp[i-1][j-1]的过程可以被压缩。
 * 发现我们只调用i-1的状态，于是只开两个数组。
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int INF = 1e9;
int a[N],dp[N],lastdp[N];
// 前者存放当前最大值，后者存放上一次的最大值

int main(){
    int n,m;
    while(~scanf("%d%d",&m,&n)){
        for(int i=1;i<=n;++i) scanf("%d",&a[i]),dp[i]=0,lastdp[i]=0;

        int tmp;
        for(int i=1;i<=m;++i){
            tmp = -INF;
            for(int j=i;j<=n;++j){
                dp[j] = max(dp[j-1],lastdp[j-1])+a[j];
                lastdp[j-1] = tmp;
                tmp = max(tmp,dp[j]);
            }
        }
        printf("%d\n",tmp);
    }
}