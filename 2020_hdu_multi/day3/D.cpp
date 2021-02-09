#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],sum[maxn],dp[maxn];

void solve(){
    int n,p;scanf("%d%d",&n,&p);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        a[i]%=p;
        sum[i]=(sum[i-1]+a[i])%p;
    }

}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}