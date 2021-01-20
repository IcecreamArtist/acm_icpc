//
// Created by Lenovo on 2020/11/22.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

struct matrix
{
    ll m[2][2];
}ans, base;
ll ans1,ans2;
matrix multi(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 2; ++k)
                tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]%MOD) % MOD;
        }
    }
    return tmp;
}
int fast_mod(ll n)
{

    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;
    ans.m[0][0] = ans.m[1][1] = 1;
    ans.m[0][1] = ans.m[1][0] = 0;
    while (n)
    {
        if (n & 1)
        {
            ans = multi(ans, base);
        }
        base = multi(base, base);
        n >>= 1;
    }
    ans1 = ans.m[0][1];
    ans2 = ans.m[0][0];
    //cout<<ans1<<endl;
    //cout<<ans.m[0][0]<<" "<<ans.m[1][0]<<" "<<ans.m[1][1]<<endl;
}

int main()
{
    ll n;scanf("%lld",&n);
    fast_mod(n);
    printf("%lld\n",ans1*ans2%MOD);

    return 0;
}