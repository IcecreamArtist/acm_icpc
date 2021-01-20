#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        if(n<3) {
            puts("0");continue;
        }
        sort(a+1,a+1+n);
        long long ans = 0;
        int num2 = 0,num1 = 0,num0 = 0;// 小2的数目，小1的数目，等于的数目
        for(int i=1;i<=n;++i){
            if(i!=1&&a[i]!=a[i-1]){
                if(a[i]==a[i-1]+1) num2 = num1,num1 = num0;
                else if(a[i]==a[i-1]+2) num2 = num0,num1 = 0;
                else num2 = num1 = 0;
                num0=0;
            }
            num0++;
            ans += (ll)(num0-1+num1+num2)*(num0+num1+num2-2)/2;
        }
        cout<<ans<<endl;
    }
}
