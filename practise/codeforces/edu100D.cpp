#include<bits/stdc++.h>
using namespace std;
int a[200004],b[200004];

void solve(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    a[0]=0;
    int cnt = 0;
    for(int i=1;i<=n;++i){
        for(int j=a[i-1]+1;j<a[i];++j){
            b[++cnt] = j;
        }
    }
    int tmp = a[n]+1;
    while(cnt<n){
        b[++cnt] = tmp++;
    }
    int ans = 0;
    cnt = 1;
    for(int i=1;i<=n;++i){
        while(cnt<=n&&b[cnt]<a[i]) cnt++;
        if(cnt>n) break;
        ans++;
        cnt++;
    }
    int ans2 = 0;
    cnt = 1;
    for(int i=1;i<=n;++i){
        while(cnt<=n&&a[cnt]<b[i]) cnt++;
        if(cnt>n) break;
        ans2++;
        cnt++;
    }
    cout<<ans-(n-ans2)+1<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}