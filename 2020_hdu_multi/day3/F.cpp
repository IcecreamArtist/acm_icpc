//
// Created by Artis on 2021/2/8.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int digit[20];
int dp[20][]; // 到第几位，最高位是多少

int dfs(int pos,bool limit,int num1,int num2,
        int num3,int num4,int num5,int num6,
        int num7,int num8,int num9){
    if(pos==0) return 1;

    int res=0;
    int mx=limit?digit[pos]:9;
    for(int i=0;i<=mx;++i){
        if() continue;
    }
}

int find(int n){
    memset(digit,0,sizeof(digit));
    int len=0;
    while(n){
        digit[++len]=n%10;
        n/=10;
    }
    return dfs(len,false,0,0,0,0,0,0,0,0,0);
}

void solve(){
    int l,r,d;scanf("%d%d%d",&l,&r,&d);
    cout<<find(l)-find(r)<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}