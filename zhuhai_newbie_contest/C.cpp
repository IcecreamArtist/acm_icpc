//
// Created by Artis on 2020/11/21.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
typedef long long ll;
int a[N];

int main(){
    int n;scanf("%d",&n);
    int mn = 1e9+7;
    ll ans = 0;

    for(int i=1;i<=n;++i) scanf("%d",&a[i]),mn = min(mn,a[i]);
    for(int i=1;i<=n;++i) ans += a[i]-mn;
    printf("%lld\n",ans);
}