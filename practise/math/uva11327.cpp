//
// 把1~200000的最小简约剩余系排列成一个数组，长度为1e10，求出第k个数是模谁的第几个最小简约剩余系。
// 思路：预处理，线性求出1~200000的欧拉函数值。然后求前缀和，对答案进行二分，查找是谁的，然后直接筛出那个数的第几个最小简约剩余系。

#include<bits/stdc++.h>
using namespace std;
const int N = 200003;
int cnt,pri[N],vis[N],phi[N];
typedef long long ll;
ll sm[N];

void solve(){
    phi[1] = 1;
    for(int i=2;i<=N;++i){
        if(!vis[i]){
            phi[i] = i-1;
            pri[++cnt] = i;
        }
        for(int j=1;j<=cnt&&1ll*pri[j]*i<=N;++j){
            vis[i*pri[j]] = 1;
            if(i%pri[j]){
                phi[i*pri[j]] = phi[i] * (pri[j]-1);
            }else{
                phi[i*pri[j]] = phi[i] * pri[j];
                break;
            }
        }
    }
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    ll n;
    solve();

    phi[1]=2;
    for(int i=1;i<=N;++i) sm[i] = sm[i-1] + phi[i];

    while(~scanf("%lld",&n),n){
        int pos = lower_bound(sm+1,sm+1+200000,n)-sm;
        if(n==1){
            puts("0/1");continue;
        }
        if(n==2){
            puts("1/1");continue;
        }
        int num = 0,id = n-sm[pos-1];
        for(int i=1;i<=pos;++i){
            if(gcd(i,pos)==1){
                num++;
                if(num==id) {
                    printf("%d/%d\n",i,pos);
                    break;
                }
            }
        }
    }
}

