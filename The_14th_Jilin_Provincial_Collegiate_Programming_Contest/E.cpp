#include<bits/stdc++.h>
using namespace std;
int a[1000005];

int solve(int l,int r) {
    int mi = 0x3f3f3f3f;
    for (int i = l; i <= r; ++i) {
        mi = min(mi, a[i]);
    }
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (mi == a[i]) ans++;
    }
    if (ans >= 2) {
        int flag = 0;
        for (int i = l; i <= r; i++) {
            if (a[i] != mi) {
                if (a[i] % mi == 0) {
                } else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) return 1;
        else {
            return (ans + 1) / 2;
        }
    }
    else return 1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int res = 0;
        for(int i=1;i<=n;++i){
            if(a[i] == 0){
                ++res;
            }
            else{
                int j;
                for(j=i;j<=n;++j) if(a[j] == 0)break;
                res += solve(i,j-1);
                i = j-1;
            }
        }
        printf ("%d\n",res);
    }
}
