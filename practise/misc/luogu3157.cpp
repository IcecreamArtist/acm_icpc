/*
 * CDQ分治模板题：三维偏序
 * 题意：给一个数组(1e5)，m(5e4)次操作，每次删除指定数字，每次删除之前输出逆序对个数。
 * 思路：每次删除指定数字，等价于时间反向，每次加入指定数字。
 * 对于一个数字的加入，该时间点增加的逆序对数等于比他早加入、位置在他之前、比他大的数+比他早加入、位置在他之后、比他小的数。
 * 分治过程中用左区间对右区间进行贡献即可。
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
typedef long long ll;
int n,m,c[maxn],p[maxn];
struct data{int t,p,v;}a[maxn],b[maxn];
ll ans[maxn];
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}
inline void insert(int x,int y){for(;x<=n;x+=(x&(-x))) c[x]+=y;}
inline int query(int x){int sm = 0;for(;x;x-=(x&(-x))) sm+=c[x];return sm;}

void cdq(int l,int r){
    if(l>=r) return;
    int mid = (l+r)>>1,tmp,ll=l-1,rr=mid;
    for(int i=l;i<=r;++i){
        if(a[i].t<=mid) b[++ll] = a[i];
        else b[++rr] = a[i];
    }
    // 将数组重新排序：mid左时间都早于右边；同时，左之中的数字按照位置从前往后排序，右之中的数字也是按位置从前往后排序
    for(int i=l;i<=r;++i) a[i]=b[i];
    tmp=l;
    for(int i=mid+1;i<=r;++i){
        // 每一个右边的，都要计算上左边中出现在他之前且比他大的
        for(;tmp<=mid&&a[tmp].p<a[i].p;tmp++) insert(a[tmp].v,1);
        ans[a[i].t]+=tmp-l-query(a[i].v);
    }
    for(int i=l;i<tmp;++i) insert(a[i].v,-1); // 撤销BIT
    tmp=mid;
    for(int i=r;i>=mid+1;--i){
        // 每一个右边的，还要计算上左边中出现在他之后且比他小的
        for(;tmp>=l&&a[tmp].p>a[i].p;tmp--) insert(a[tmp].v,1);
        ans[a[i].t]+=query(a[i].v-1);
    }
    for(int i=tmp+1;i<=mid;++i) insert(a[i].v,-1); // 撤销BIT
    cdq(l,mid);cdq(mid+1,r);
}

int main(){
    n=read(),m=read();
    int time = n,x;
    for(int i=1;i<=n;++i) a[i].v=read(),a[i].p=i,p[a[i].v]=i;
    for(int i=1;i<=m;++i) x=read(),a[p[x]].t=time--;
    for(int i=1;i<=n;++i) if(!a[i].t) a[i].t=time--;
    cdq(1,n);
    // 依次删除每个数，等价于反向加入每个数
    for(int i=1;i<=n;++i) ans[i]+=ans[i-1]; // 反向加入每个数，到第几次的结果。
    for(int i=n;i>=n-m+1;--i) printf("%lld\n",ans[i]);
}
