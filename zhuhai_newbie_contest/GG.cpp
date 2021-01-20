/*
 * 题意：2e5只牛，每只牛因不同的温度有不同的产奶量，范围介于0~1000之间。求使得奶量总和最大的温度。
 * 温度范围：0~1e9.
 * 因为牛的数目只有2e5，因此考虑离散化最适温度。
 * 用个map储存这个对应。
 * 然后对每个x\y\z，差分。
 * 最后一遍遍历，找答案最大即可。
 */
#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e4+6;
int x[N],y[N],z[N],a[N],b[N];
int tem[N<<2],sum[N<<2],tem2[N<<2];

int main(){
    scanf("%d",&n);
    int cnt = 0;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d%d%d",&a[i],&b[i],&x[i],&y[i],&z[i]);
        tem[++cnt] = a[i];tem[++cnt] = b[i];
    }
    sort(tem+1,tem+1+cnt);
    int tot = unique(tem+1,tem+1+cnt)-tem-1;
    cnt = 0;
    for(int i=1;i<=tot;++i){
        if(tem[i]-tem[i-1]>1&&i!=1) tem2[++cnt] = tem[i-1]+1;
        tem2[++cnt] = tem[i];
    }
    for(int i=1;i<=n;++i){
        int l = lower_bound(tem2+1,tem2+1+cnt,a[i]) - tem2;
        int r = lower_bound(tem2+1,tem2+1+cnt,b[i]) - tem2;
        sum[0]+=x[i],sum[l]-=x[i],sum[l]+=y[i],sum[r+1]-=y[i];
		sum[r+1]+=z[i],sum[cnt+1]-=z[i];
    }
    long long ans = 0,mx = 0;
    for( int i=0 ; i<=cnt+1 ; i++ ){
        ans=ans+sum[i];
        mx=max(mx,ans);
    }
    printf("%lld\n",mx);
}
