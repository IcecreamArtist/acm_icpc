#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+6;
typedef long long ll;
ll a[maxn];
// 差分

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
        ll ans1=0,ans2=0;
        for(int i=2;i<=n-1;++i) {
            ans1+=abs(a[i]-a[i-1]);
            ans2 = max(ans2,abs(a[i+1]-a[i])+abs(a[i]-a[i-1])-abs(a[i+1]-a[i-1]));
        }
        ans1+=abs(a[n]-a[n-1]);
        ans2=max(ans2,abs(a[1]-a[2]));
        ans2=max(ans2,abs(a[n]-a[n-1]));
        cout<<ans1-ans2<<endl;
    }
}