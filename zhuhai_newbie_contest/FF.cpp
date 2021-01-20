//
// Created by Lenovo on 2020/11/22.
//

#include<bits/stdc++.h>
using namespace std;
// shu wei dp
const int N = 30;
typedef long long ll;
ll dp[N][3]; // 0：前面是其他,1：前面是4,2：前面是48
int digit[N];

int dfs(int pos,int pre,bool ismax){
    if(pos==0) return 1;
    int res = 0;
    if(!ismax&&dp[pos][pre]!=-1) return dp[pos][pre];
    int mx = ismax?digit[pos]:9;
    for(int i=0;i<=mx;++i){
        if(i==6&&pre==2) continue;
        if(i==8&&pre==1) res += dfs(pos-1,2,ismax&&(i==mx));
        else if(i==4) res += dfs(pos-1,1,ismax&&(i==mx));
        else res += dfs(pos-1,0,ismax&&(i==mx));
    }
    if(!ismax) dp[pos][pre] = res;
    //cout<<"pos = "<<pos<<"pre = "<<pre<<"ismax = "<<ismax<<"res = "<<res<<endl;
    return res;
}

int solve(int n){
    memset(digit,0,sizeof(digit));
    int len = 0;
    while (n){
        digit[++len] = n % 10;
        n/=10;
    }
    return dfs(len,0,1);
}

int main(){
    ll n;scanf("%lld",&n);
    memset(dp,-1,sizeof(dp));
    ll ans = solve(n);   // 1~n中没有486的数字的个数
    printf("%lld\n",n-ans+1);    // n-ans，即有的个数
}