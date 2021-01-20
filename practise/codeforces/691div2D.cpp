#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 103;
int dp[maxn][maxn*maxn];
/*
 * ans = all max( k min( A_s , B_s+1/2(B-B_s) ) )
 * ---> ans = all max( k min( A_s , 1/2(B+B_s) )
 * 背包dp
 * dp[i][k][A] = max(dp[i-1][k][A],dp[i-1][k-1][A-A_i]+B_i)
 * ans[k] = max( min( 1/2dp[i][k][A]+B/2, A) )
 */

vector<int> a,b;

int main(){
    int n;scanf("%d",&n);
    int As=0,Bs=0;
    for(int i=1;i<=n;++i){
        int x,y;scanf("%d%d",&x,&y);
        a.push_back(x);b.push_back(y);
        As+=x,Bs+=y;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=n;++i){
        for(int k=i;k>=1;--k){  // 背包dp空间优化，记得反过来。
            for(int A=As;A>=a[i-1];--A){
                if(dp[k-1][A-a[i-1]]!=-1) dp[k][A] = max(dp[k][A],dp[k-1][A-a[i-1]]+b[i-1]);
            }
        }
    }
    double ans;
    for(int k=1;k<=n;++k){
        ans = 0;
        for(int A=0;A<=As;++A){
            if(~dp[k][A])
            ans = max(ans,min((double)A,(double)0.5*dp[k][A]+(double)0.5*Bs));
        }
        cout<<ans<<" ";
    }
}
