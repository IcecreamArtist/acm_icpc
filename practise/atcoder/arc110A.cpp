//
// Created by Lenovo on 2020/12/5.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int main(){
    ll ans = 1;
    for(ll i=1;i<=30;++i) ans = lcm(ans,i);
    for(int i=1;i<=1000;++i){
        ll tmp = ans+i;
        int flg=0;
        for(int j=11;j<=30;++j) if(tmp%j!=1){
            flg=1;
            break;
        }
        if(!flg) cout<<tmp<<endl;
    }
}