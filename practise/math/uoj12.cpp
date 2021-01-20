/*
 * 题意：已知ab=k，a,b为g的倍数，求a+b最大值和最小值。
 * 设a<b。已知l/g，只需枚举k1,k2，使得有k1*k2=l/g
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        ll a,b,g,l;scanf("%lld%lld",&g,&l);
        printf("%lld %lld\n",2*(ll)sqrt((long double)g*l),g+l);
    }
}