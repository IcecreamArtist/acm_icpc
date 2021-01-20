/*
 * 题意：n个数，每个数为ai，m个询问，求：l到r区间ai*num(ai)的和
 * 带修莫队模板
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+6;
int n,m,a[N],sqn,qcnt,ccnt,num[N*10];
long long ans[N],sm;

struct query{
    int l,r,id,t;
    bool operator <(const query &b)const{
        if(l/sqn!=b.l/sqn) return l/sqn<b.l/sqn;
        if(r/sqn!=b.r/sqn) return r/sqn<b.r/sqn;
        return t<b.t;
    }
}q[N];

struct modify{
    int pos,pre,nex;
}c[N];

template <typename _Tp>
inline void IN(_Tp& dig){
    char c;dig = 0;
    while(c=getchar(),!isdigit(c));
    while(isdigit(c)) dig = dig * 10 + c -'0',c = getchar();
}

void add(int p){
    sm-=(long long)num[a[p]]*num[a[p]]*a[p];
    sm+=(long long)(++num[a[p]])*num[a[p]]*a[p];
}

void del(int p){
    sm-=(long long)num[a[p]]*num[a[p]]*a[p];
    sm+=(long long)(--num[a[p]])*num[a[p]]*a[p];
}

int main(){
    //freopen("input.txt","r",stdin);
    IN(n);IN(m);sqn = ceil(pow(n,(double)2/(double)3));
    for(int i=1;i<=n;++i) IN(a[i]);
    for(int i=1,x,y;i<=m;++i) {
        char str[4];
        if(scanf("%s",str),IN(x),IN(y),str[0]=='Q')
            q[++qcnt].l = x,q[qcnt].r = y,q[qcnt].id = qcnt,q[qcnt].t = ccnt;
        else
            c[++ccnt].pos = x,c[ccnt].nex = y,c[ccnt].pre = a[x],a[x] = y;
    }
    sort(q+1,q+1+qcnt);
    for(int i=ccnt;i>=1;--i) a[c[i].pos] = c[i].pre;
    for(int i=1,l=1,r=0,t=0;i<=qcnt;++i){
        while(l>q[i].l) add(--l);
        while(r<q[i].r) add(++r);
        while(l<q[i].l) del(l++);
        while(r>q[i].r) del(r--);
        while(t<q[i].t){
            int p = c[++t].pos;
            if(l<=p&&r>=p) del(p);
            a[p] = c[t].nex;
            if(l<=p&&r>=p) add(p);
        }
        while(t>q[i].t){
            int p = c[t].pos;
            if(l<=p&&r>=p) del(p);
            a[p] = c[t].pre;
            if(l<=p&&r>=p) add(p);
            t--;
        }
        ans[q[i].id] = sm;
    }
    for(int i=1;i<=qcnt;++i) printf("%lld\n",ans[i]);
}
