/*
 * 题意：1~n的约瑟夫环，求第m个处死者的原序号，步长为k。k,n,m<=1e18,min(n,k)<=2e6
 * 思路：首先我们要知道约瑟夫环的递推公式：（约瑟夫环问题：处死第m个，求最后存活者的初始编号）
 * 证明见 https://blog.csdn.net/u011500062/article/details/72855826
 * 从0开始编号：f(n,m) = (f(n-1,m)+m)%n, f(1,m) = 0
 * 从1开始编号：f(n,m) = (f(n-1,m)+m)%n. f(1,m) = 0,最后答案 = f(n,m) + 1.
 * 然后，考虑第m个处死者的原序号如何求得：
 * 当进行到第m轮时，要处死第m个人，此时剩下(n-m+1)个人。
 * 因此，f(n-m+1,m) = (k-1)%(n-m+1). 即，f代表，进行到剩余n-m+1个人时，该人的编号为k-1(以0为起点)。
 * 然后递推出其初始编号。利用公式f(n,m) = (f(n-1,m)+m)%n，只不过起始条件有所改变。答案+1即可。
 * 时间复杂度为O(m)。
 * 但注意到，在这道题中，m<=1e18.
 * 如果m<k，m<=2e6，可直接暴力；但如果m>k，m<=1e18，要寻找压缩这个递推过程的思路。
 * 注意到，当m>k，此时有k<=2e6.此时，f(n-m+1,m) = (k-1)%(n-m+1)可能远小于n-m+2~n。
 * 即，可能起始有一段递推过程，取模没有意义。
 * 如此一来，就可以直接去掉这一段的取模操作，这一段的加法就可以被压缩为乘法。
 * 为什么压缩这个过程就可以使得时间复杂度变安全了呢？
 * https://blog.csdn.net/xiji333/article/details/101159844
 * 假若起始这一段可以被忽略取模的过程终止于第t次。
 * 第0次：pos = (k-1)%(n-m+1)
 * 第1次：pos2 = (pos+k)%(n-m+2)
 * 第2次：pos3 = (pos+2*k)%(n-m+3)
 * ...
 * 第t次：post = (pos+t*k)%(n-m+1+t)
 * 如果pos+t*k<n-m+t+1，这整个过程都不需要取模。因为左边的增幅大于右边。往前走更不可能需要取模。
 * 此时t<(n-m+1-pos)/(k-1)。t次加法可以被合并成1次乘法。
 * 到第t+1次，需要取模，取模之后，又有可能遇到可以压缩的状况。
 * 最差情况：n=m=1e18，k=2e6、此时t = tmin -> 0.最多需要操作数 = 55875734
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read(){
    char ch = getchar();int x=0,f=1;while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();return x*f;
}

int main(){
    int t = read(),cas = 0;
    while(t--){
        ll n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
        ll ans;
        if(k==1) ans = m-1;
        else if(m<=k){
            ans = (k-1)%(n-m+1);
            for(ll i=n-m+2;i<=n;++i) ans = (ans+k)%i;
        }else{
            ans = (k-1)%(n-m+1);
            ll cur = n-m+1;
            while(1){
                ll tt = (cur-ans)/(k-1);
                if(tt*(k-1)==cur-ans) --tt;
                tt = min(tt,n-cur);
                ans += k*tt;
                cur += tt;
                ans=ans%cur;
                if(cur==n) break;
                ++cur;
                ans=(ans+k)%cur;
                if(cur==n) break;
            }
        }

        printf("Case #%d: %lld\n",++cas,ans+1);
    }
}