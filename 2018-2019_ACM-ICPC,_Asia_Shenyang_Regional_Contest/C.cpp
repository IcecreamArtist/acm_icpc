/*
 * 题意：permutation(n)，前k个数被排序成新数列，这个新数列的最长上升子序列长度为至少n-1.
 * 求一开始的permutation有多少种。
 * 思路：
 * (1)最长上升子序列长度为n: A(k,k)
 * (2)最长上升子序列长度为n-1：
 * (2.1)前k个中的最大数字为k：前面A(k,k)，那么后面n-k个数，为[n-k,n]且满足最长上升子序列长度为n-1。找规律得种类
 * 数目=(n-k-1)^2，再乘上前k个的所有排序A(k,k)
 * (2.2)前k个中的最大数字为k+1：那么前k个任意一个可以与k+1交换，而这任意一个可以放在n-k所有位置。即k*(n-k)
 * (2.3)前k个中的最大数字大于k+1：前k个一定是[1,k-1]和这个数。k可以放在除了第k+1之外（与2.2重复）任意一个位置。(n-k-1)
 * 因此答案为ans = A(k,k)*(1+(n-k-1)^2+k*(n-k)+n-k-1)
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    for(int cas = 1;cas<=t;++cas){
        ll n,k,q;
        ll ans = 1;
        scanf("%lld%lld%lld",&n,&k,&q);
        if(k>n-1) k = n-1;
        for(int i=1;i<=k;++i) ans=ans*i%q;
        ans=ans*((n-k-1)*(n-k-1)+(k+1)*(n-k))%q;
        printf("Case #%d: %lld\n",cas,ans);
    }
}