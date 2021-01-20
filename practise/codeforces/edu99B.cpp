#include <bits/stdc++.h>
using namespace std;
int ans[2000005];

int main(){
    int t;scanf("%d",&t);
    ans[1]=1;
    for(int i=2,cnt=3;i<=1000000;i+=cnt,cnt++){
        ans[i]=cnt;
        ans[i+1]=cnt-1;
        for(int j=i+2;j<i+cnt;++j) ans[j]=cnt;
    }
    while(t--){
        int x;scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
}