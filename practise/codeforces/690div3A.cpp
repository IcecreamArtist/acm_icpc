#include<bits/stdc++.h>
using namespace std;
int a[304],b[304];
void solve(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    int cnt = 0,cnt2 = n+1;
    for(int i=1;i<=n;++i){
        if(i&1) b[i] = a[++cnt];
        else b[i] = a[--cnt2];
    }
    for(int i=1;i<n;++i) cout<<b[i]<<" ";
    cout<<b[n]<<endl;
}
int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}
