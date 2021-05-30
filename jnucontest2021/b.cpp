#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+5;
int a[maxn];
ll sum[maxn];

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int i=1;i<=n;++i) {
            sum[i] = sum[i-1] + a[i];
        }
        sort(sum,sum+1+n);
        ll ans = 0;
        for(int i=0;i<(n+1)/2;++i) {
            ans -= sum[i];
        }
        for(int i=(n+1)/2;i<=n;++i){
            ans += sum[i];
        }
        cout<<(ans%(1000000007)+1000000007)%1000000007<<endl;
    }
}
