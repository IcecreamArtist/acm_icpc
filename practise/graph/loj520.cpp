/*
 * 题意：给一张完全图。边权为点权之差平方。求哈密顿回路，总边权最小。
 * 思路：每个点连接两个点。求最小总和。数学。
 */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
typedef long long ll;

int a[N],vis[N];

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    ll ans = 0,last = a[1];
    int i;
    //for(int i=1;i<=n;++i) printf("%d ",a[i]);
    for(i=3;i<=n;i+=2) {
        ans += (ll)(a[i]-last)*(a[i]-last);
        vis[i] = 1;
        last = a[i];
    }
    if(i!=n) ans += (ll)(last-a[n])*(last-a[n]);
    last = a[n];
    for(i=n-1;i>=1;i--) {
        if(vis[i]) continue;
        ans += (ll)(a[i]-last)*(a[i]-last);
        last = a[i];
    }
    if(i!=1) ans += (ll)(last-a[1])*(last-a[1]);
    printf("%lld\n",ans);
}