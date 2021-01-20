#include<bits/stdc++.h>
using namespace std;
int a[505];
int t;
/*
 * 贪心做法。
 * dp做法：dp(i,j)最少操作次数：上一个与x交换的数字是a_i，现在a_i=j
 */

int main(){
    scanf("%d",&t);
    while(t--){
        int n,x;scanf("%d%d",&n,&x);
        int flg,ans = 0;
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        while(1){
            flg = 1;
            int pos = 0,fir = 0;
            for(int i=1;i<=n;++i) {
                if(a[i]<a[i-1]) flg=0;
                if(a[i]>x&&!fir) pos = i,fir=1;
            }
            if(flg) break;
            if(pos==0) break;
            swap(a[pos],x);
            ans++;
        }
        if(!flg) puts("-1");
        else printf("%d\n",ans);
    }
}
