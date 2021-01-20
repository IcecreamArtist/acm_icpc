//
// Created by Lenovo on 2020/11/22.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
typedef long long ll;
char ans[N];
char str[] = "abcdefghijklmnopqrstuvwxyz0123456789";

int main(){
    ll l,r;scanf("%d%d",&l,&r);
    ll pw = 1;
    for(ll i=0;i<=35;++i){
        for(ll j=l;j<=r;++j){
            if(j%pw==0) ans[j-l] = str[i];
        }
        pw<<=1; // times 2
    }
    printf("%s\n",ans);
}