#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int x,y;
ll dp[34][2][2];
// handle two numbers simultaneously

int a[34],b[34];

ll dfs(int pos,int isla,int islb){
    if(pos==-1) return 1;
    if(dp[pos][isla][islb]!=-1) return dp[pos][isla][islb];
    int mxi = isla?a[pos+1]:1,mxj = islb?b[pos+1]:1;
    ll ans = 0;
    for(int i=0;i<=mxi;++i){
        for(int j=0;j<=mxj;++j){
            if((i&j)==0)
            ans = (ans + dfs(pos-1,isla&&i==mxi,islb&&j==mxj))%MOD;
        }
    }
    return dp[pos][isla][islb] = ans;
}
void solve(){
    scanf("%d%d",&x,&y);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(dp,-1,sizeof(dp));
    int cnt1=0,cnt2=0;
    while(x){
        a[++cnt1]=x&1;
        x>>=1;
    }
    while(y){
        b[++cnt2]=y&1;
        y>>=1;
    }
    ll ans = 0;
    for(int i=0;i<max(cnt1,cnt2);++i){
        ll res = 0;
        // i_i = 1,j_i = 0
        if(i<cnt1) res += dfs(i-1,i==cnt1-1,i>=cnt2);
        // i_i = 0,j_i = 1
        if(i<cnt2) res += dfs(i-1,i>=cnt1,i==cnt2-1);
        ans = (ans + res*(i+1))%MOD;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
