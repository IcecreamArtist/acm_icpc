#include <bits/stdc++.h>
using namespace std;
int cnt[103];

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int tmp,ans = 0;
        for(int i=1;i<=n;++i) cin>>tmp,cnt[tmp]++;
        for(int i=1;i<=m;++i) {
            cin>>tmp;
            if(cnt[tmp]) ans ++;
        }
        cout<<ans<<endl;
        memset(cnt,0,sizeof(cnt));
    }
}