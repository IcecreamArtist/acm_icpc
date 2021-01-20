/*
 * 带修莫队模板题
 * 题意：一个数组1e5, 1e5次查询或修改，求区间共有多少种不同数字
 */
#include <bits/stdc++.h>
using namespace std;
int n,m,qcnt,rcnt,sqn,ans;
const int N = 2e5;
int a[N],res[N];
int num[N*10];
// quick read
template <typename _Tp>
inline void IN(_Tp& dig){
    char c;dig = 0;
    while(c=getchar(),!isdigit(c));
    while(isdigit(c)) dig = dig * 10 + c -'0',c = getchar();
}
struct query{
    int id,l,r,t;  // id, left, right, time
    bool operator < (const query &b) const{
        if(l/sqn!=b.l/sqn) return l/sqn<b.l/sqn;
        if(r/sqn!=b.r/sqn) return r/sqn<b.r/sqn;
        return t<b.t;
    }
}q[N];
struct modify{
    int pos,pre,nex;  // position, previous, next
}rr[N];
int main(){
    IN(n),IN(m),sqn = ceil(pow(n,(double)2/(double)3));
    for(int i=1;i<=n;++i) IN(a[i]);
    for(int i=1;i<=m;++i){
        char str[4];
        scanf("%s",str);
        if(str[0]=='Q'){
            // query
            q[++qcnt].id = qcnt;
            IN(q[qcnt].l),IN(q[qcnt].r);
            q[qcnt].t = rcnt;
        }else {
            // modify
            IN(rr[++rcnt].pos),IN(rr[rcnt].nex);
            rr[rcnt].pre = a[rr[rcnt].pos];
            a[rr[rcnt].pos] = rr[rcnt].nex;  // record all the information
        }
    }
    // recover the information in a
    for(int i=rcnt;i>=1;--i) a[rr[i].pos] = rr[i].pre;
    // sort
    sort(q+1,q+1+qcnt);
    // do the operations
    for(int i=1,l=1,r=0,t=0;i<=qcnt;++i){
        while(l>q[i].l) ans+=!num[a[--l]]++;
        while(r<q[i].r) ans+=!num[a[++r]]++;
        while(l<q[i].l) ans-=!--num[a[l++]];
        while(r>q[i].r) ans-=!--num[a[r--]];
        // then we need to travel through time
        while(t<q[i].t) {
            // time is before, so we do those updates
            if(l<=rr[++t].pos&&r>=rr[t].pos) ans-=!--num[a[rr[t].pos]];
            a[rr[t].pos] = rr[t].nex;
            if(l<=rr[t].pos&&r>=rr[t].pos) ans+=!num[a[rr[t].pos]]++;
        }
        while(t>q[i].t) {
            if(l<=rr[t].pos&&r>=rr[t].pos) ans-=!--num[a[rr[t].pos]];
            a[rr[t].pos] = rr[t].pre;
            if(l<=rr[t].pos&&r>=rr[t].pos) ans+=!num[a[rr[t].pos]]++;
            t--;
        }
        res[q[i].id] = ans;
    }
    for(int i=1;i<=qcnt;++i) printf("%d\n",res[i]);
}