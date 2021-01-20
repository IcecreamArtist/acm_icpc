//
// 欧拉函数线性筛裸题
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
// sieve euler functions
int phi[N],vis[N],pri[N],cnt;

void solve(){
    phi[1] = 1;
    for(int i=2;i<=N;++i){
        if(!vis[i]) {
            pri[++cnt] = i;
            phi[i] = i-1;
        }
        for(int j=1;j<=cnt&&1ll*i*pri[j]<=N;++j){
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


int main(){
    int t,a;scanf("%d",&t);
    solve();
    while(t--) scanf("%d",&a),printf("%d\n",phi[a]);
}