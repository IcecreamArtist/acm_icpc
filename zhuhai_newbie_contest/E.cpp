//
// Created by Artist on 2020/11/21.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
typedef long long ll;
const int MOD = 1e9+7;
char a[N];
ll dp[N];
ll g[N];
int main(){
    scanf("%s",a+1);
    int len = strlen(a+1);
    ll ans = 0,pw = 0;
    for(int i=1;i<=len;++i){
        dp[i] = ((dp[i-1]*11)%MOD+(a[i]-'0')*pw%MOD+g[i])%MOD;
        pw=(((pw+1)*2)%MOD-1+MOD)%MOD;
        g[i+1] = (g[i]*10 + a[i]-'0')%MOD;
    }
    printf("%lld\n",dp[len]);
}