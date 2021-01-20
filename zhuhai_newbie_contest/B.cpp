# include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
typedef long long ll;
ll a[N];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]),a[i]+=a[i-1];
    for(int i=1;i<=m;++i){
        ll tmp;scanf("%lld",&tmp);
        int pos = lower_bound(a+1,a+1+n,tmp)-a;
        printf("%d %lld\n",pos,tmp-a[pos-1]);
    }
}

