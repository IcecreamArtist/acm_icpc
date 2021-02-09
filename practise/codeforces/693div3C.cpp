//
// Created by Artis on 2021/1/26.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+4;
int a[maxn];
long long b[maxn];  // farthest

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long ans=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=n;i>=1;--i){
            if(a[i]+i>n) b[i]=a[i];
            else b[i]=b[i+a[i]]+a[i];
            ans=max(b[i],ans);
        }
        cout<<ans<<endl;
    }
}