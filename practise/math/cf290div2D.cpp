/*
 * 裴蜀定理：选取总价格最便宜的数字集合，他们互质。
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 304;
const int inf = 2e9+5;
map<int,int> dp;
int l[N],c[N];

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

void update(int a,int b){
    if(dp.find(a)==dp.end()) dp[a] = inf;
    dp[a] = min(dp[a],b);
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&l[i]);
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    for(int i=1;i<=n;++i){
        update(l[i],c[i]);
        for(auto it:dp) update(gcd(l[i],it.first),it.second+c[i]);
    }
    if(dp.find(1)==dp.end()) return puts("-1");
    else printf("%d\n",dp[1]);
}
