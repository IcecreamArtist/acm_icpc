/*
 * 题意：四个点，每一步可移动一个点四个方向走一步。最少步数使得四个点构成平行于坐标轴的正方形。
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll x,y;
}tmp[5],p[5];
ll pt[5];

int main(){
    ll t;scanf("%lld",&t);
    while(t--){
        for(int i=1;i<=4;++i) scanf("%lld%lld%",&tmp[i].x,&tmp[i].y),pt[i]=i;
        long long ans = 10000000000000000,res;
        do{
            for(int i=1;i<=4;++i) p[i] = tmp[pt[i]];
            res = max(p[1].x,p[2].x)-min(p[1].x,p[2].x)+max(p[3].x,p[4].x)-min(p[3].x,p[4].x);
            res += max(p[1].y,p[3].y)-min(p[1].y,p[3].y)+max(p[2].y,p[4].y)-min(p[2].y,p[4].y);
            ll segxl = min(p[3].x,p[4].x)-max(p[1].x,p[2].x);
            ll segxr = max(p[3].x,p[4].x)-min(p[1].x,p[2].x);
            ll segyl = min(p[2].y,p[4].y)-max(p[1].y,p[3].y);
            ll segyr = max(p[2].y,p[4].y)-min(p[1].y,p[3].y);
            res += 2*max(0ll,max(segxl,segyl)-min(segxr,segyr));
            ans = min(ans,res);
        }while(next_permutation(pt+1,pt+1+4));
        printf("%lld\n",ans);
    }
}