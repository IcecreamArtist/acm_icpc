//
// Created by Artis on 2021/1/24.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000003;
const ll inf = 1e17;
ll r[maxn];
int main(){
    int n;ll d;
    cin>>n>>d;
    ll mx=-inf,mn=inf,mx2=-inf,mn2=inf;
    for(int i=1;i<=n;++i){
        scanf("%lld",&r[i]);
        mx=max(mx,-(i-1)*d+r[i]);
        mn=min(mn,-(i-1)*d+r[i]);
        mx2=max(mx2,(i-1)*d+r[i]);
        mn2=min(mn2,(i-1)*d+r[i]);
    }
    ll ans1=mx-mn,ans2=mx2-mn2;
    ll ans=min(ans1,ans2);
    printf("%lld.%d\n",ans/2,(ans%2==0)?0:5);
}
