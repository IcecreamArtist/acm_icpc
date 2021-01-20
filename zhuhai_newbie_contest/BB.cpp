//
// Created by Lenovo on 2020/11/22.
//

# include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
const int MOD = 1e9+7;
ll f[N];

int main(){
    int n;scanf("%d",&n);
    ll ans = 0,las = 1,las2 = 0,cur = 1;
    for(int i=2;i<=n;++i){
        cur = (las + las2)%MOD;
        las2 = las;
        las = cur;
        las2%=MOD;
        cur%=MOD;
        las%=MOD;
        cout<<cur<<endl;
        ans = (ans + cur*cur%MOD )%MOD;
    }
    printf("%lld\n",(ans+1)%MOD);
}