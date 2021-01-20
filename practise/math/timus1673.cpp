//
//  solution: https://blog.csdn.net/weixin_45497996/article/details/110825864
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll ans=200000000000;
int pri[N],vis[N],cnt,m;

void get_prime(){
    for(int i=2;i<=50000;++i){
        if(!vis[i]) pri[++cnt] = i;
        for(int j=1;j<=cnt&&i*pri[j]<=50000;++j){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) break;
        }
    }
    // 因为空间问题，只能筛出sqrt n的质数. 然后我们在dfs过程中对huge prime进行特判。
}

bool isprime(int n){
    int k=(int)sqrt(n+0.5);
    for(int i=2;i<=k;++i) if(n%i==0) return 0;
    return 1;
}

void dfs(int k,int rem,ll pro){
    // now at k th prime, the previous product is pro, the remainder is rem
    if(pro>=ans) return;
    if(rem==1){ans = pro;return;}
    if(rem>m&&isprime(rem+1)) ans = min(ans,pro*(rem+1));
    for(int i=k+1;pri[i]-1<=m;++i){
        if(pri[i]-1>rem) break;
        if(rem%(pri[i]-1)==0){
            int x = rem/(pri[i]-1);ll y = pro*pri[i];
            dfs(i,x,y);
            while(x%pri[i]==0){
                x/=pri[i];y*=pri[i];
                dfs(i,x,y);
            }
        }
    }
}

int main(){
    // 因此，组合必在10个质数之内。
    int k;scanf("%d",&k);
    m = (int)sqrt(k+0.5);
    get_prime();
    dfs(0,k,1);
    if(ans==200000000000) cout<<0<<endl;
    else cout<<ans<<endl;
}
