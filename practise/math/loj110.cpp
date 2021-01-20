/*
 * 线性求逆元
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 3e6+6;
int inv[N];

void solve(int n,int p){
    inv[1] = 1;
    for(int i=2;i<=n;++i){
        inv[i] = (long long)(p-p/i)*inv[p%i]%p;
    }
}

int main(){
    int n,p;scanf("%d%d",&n,&p);
    solve(n,p);
    for(int i=1;i<=n;++i) printf("%d\n",inv[i]);
}