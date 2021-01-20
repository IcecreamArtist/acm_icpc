#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int fac[N];

void init(){
    for(int i=1;i<1e3;++i){
        int ans = 0;
        for(int j=1;j<=i;++j) if(i%j==0) ans++;
        fac[i] = ans;
    }
}

int main(){
    int t;scanf("%d",&t);
    init();
    while(t--){
        int m,n;scanf("%d%d",&m,&n);
        int ans = 0;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(fac[i]*fac[j]%2) ans++;
            }
        }
        printf("%d\n",ans);
    }
}
