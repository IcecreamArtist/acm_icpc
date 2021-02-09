#include<bits/stdc++.h>
using namespace std;
const int inf=0x7f7f7f7f;
int a[101],b[101];
int dp[101][101];

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n;
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        cin>>m;
        for(int i=1;i<=m;++i)
            scanf("%d",&b[i]);
        int ans=0;
        memset(dp,-inf,sizeof(dp));
        dp[1][0]=a[1],dp[0][1]=b[1],dp[0][0]=0;
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(i&&j) dp[i][j]=max(dp[i-1][j]+a[i],dp[i][j-1]+b[j]);
                else if(j) dp[i][j]=dp[i][j-1]+b[j];
                else if(i) dp[i][j]=dp[i-1][j]+a[i];
                ans=max(dp[i][j],ans);
            }
        }
        cout<<ans<<endl;
    }
}