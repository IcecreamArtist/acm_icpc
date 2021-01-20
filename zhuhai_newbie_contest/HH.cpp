//
// Created by Lenovo on 2020/11/22.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
typedef long long ll;
int a[N];
int cnt[N*10];
int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;++i){
        char str[4];scanf("%s",str);
        if(str[0]=='C'){
            int l,r;scanf("%d%d",&l,&r);
            a[l] = r;
        }else{
            ll ans = 0;
            int l,r;scanf("%d%d",&l,&r);
            memset(cnt,0,sizeof(cnt));
            for(int j=l;j<=r;++j){
                cnt[a[j]]++;
            }
            for(int j=l;j<=r;++j){
                ans += cnt[a[j]]*a[j];
            }
            printf("%lld\n",ans);
        }
    }
}