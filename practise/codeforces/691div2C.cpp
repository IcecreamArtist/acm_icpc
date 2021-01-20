#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
;
}
ll a[200004],b[200003];

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    sort(a+1,a+1+n);
    ll res = a[n]-a[n-1];
    for(int i=2;i<=n;++i) res = gcd(res,a[i]-a[i-1]);
    for(int i=1;i<=m;++i) {
        cout<<gcd(res,b[i]+a[1])<<" ";
    }
    cout<<endl;
}
