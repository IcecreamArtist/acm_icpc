/*
 * 莫队模板题
 * 一个数组,N(5e4)个数字,M(5e4)次查询：区间中抽两个数字,两者相等的概率。
 * 先上暴力做法
 */
#include <bits/stdc++.h>
using namespace std;
int n,m,maxn;
typedef long long ll;
const int N = 5e4+5;
int a[N],cnt[N];
ll sum;
struct node{
    int l,r,id;
    bool operator < (const node &b) const{
        if(l/maxn!=b.l/maxn) return l<b.l;
        return r<b.r;
    }
}q[N];

void add(int i){
    sum += cnt[i];
    cnt[i]++;
}

void del(int i){
    cnt[i]--;
    sum -= cnt[i];
}

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll ans1[N],ans2[N];

int main(){
    scanf("%d%d",&n,&m);
    maxn = sqrt(n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=0;i<m;++i) scanf("%d%d",&q[i].l,&q[i].r),q[i].id = i;
//    下面是暴力做法
//    for(int i=1;i<=m;++i) {
//        memset(cnt,0,sizeof(cnt));
//        int fz = 0,fm = (q[i].r-q[i].l+1)*(q[i].r-q[i].l)/2;
//        if(fm==0) {puts("0/1");continue;}
//        for(int j = q[i].l;j<=q[i].r;++j){
//            fz += cnt[a[j]];
//            cnt[a[j]]++;
//        }
//        if(fz==0) {puts("0/1");continue;}
//        int g = gcd(fz,fm);
//        printf("%d/%d\n",fz/g,fm/g);
//    }
    // 下面是莫队算法
    sort(q,q+m);
    for(int i=0,l=1,r=0;i<m;++i){
        if(q[i].l==q[i].r){ans1[q[i].id]=0,ans2[q[i].id]=1;continue;}
        while(l>q[i].l) add(a[--l]);
        while(r<q[i].r) add(a[++r]);
        while(l<q[i].l) del(a[l++]);
        while(r>q[i].r) del(a[r--]);
        ans1[q[i].id] = sum;
        ans2[q[i].id] = (ll)(r-l+1)*(r-l)/2;
    }
    for(int i=0;i<m;++i){
        if(ans1[i]!=0){
            ll g = gcd(ans1[i],ans2[i]);
            ans1[i] /= g, ans2[i] /= g;
        }
        else ans2[i] = 1;
        printf("%lld/%lld\n",ans1[i],ans2[i]);
    }
}