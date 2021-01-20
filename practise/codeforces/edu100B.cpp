//#include<bits/stdc++.h>
//using namespace std;
//int a[55];
//typedef long long ll;
//
//void solve(){
//    int n;scanf("%d",&n);
//    ll smodd = 0,smeven = 0;
//    for(int i=1;i<=n;++i){
//        scanf("%d",&a[i]);
//        if(i&1) smodd+=a[i]-1;
//        else smeven += a[i]-1;
//    }
//    if(smeven>=smodd){
//        for(int i=1;i<=n;++i){
//            if(i&1) cout<<1<<" ";
//            else cout<<a[i]<<" ";
//        }
//    }else{
//        for(int i=1;i<=n;++i){
//            if(i&1) cout<<a[i]<<" ";
//            else cout<<1<<" ";
//        }
//    }
//    cout<<endl;
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
pair<ll,ll>p[55];
ll c[55],ans[55];
// 2的幂次
void solve(){
    int n;scanf("%d",&n);
    ll tmp=1;
    for(int i=1;i<=n;++i){
        scanf("%lld",&p[i].first);
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=n;++i){
        while((tmp<<1ll)<=p[i].first) tmp<<=1;
        c[i]=tmp;
    }
    for(int i=1;i<=n;++i) ans[p[i].second]=c[i];
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;
}


int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}