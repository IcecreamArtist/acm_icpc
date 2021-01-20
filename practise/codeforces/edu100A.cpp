#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    int k = (a+b+c)/9;
    if((a+b+c)%9==0&&k<=min({a,b,c})){
        puts("Yes");
    }else puts("NO");
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}