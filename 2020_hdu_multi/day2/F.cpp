#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn = 2e6+4;
int a[maxn],b[maxn],c[maxn];
ll fib[maxn];

void init(){
    fib[1]=1,fib[2]=2;
    for(int i=3;i<maxn;++i)
        fib[i]=fib[i-1]+fib[i-2];
}

int main(){
    int t;cin>>t;
    init();
    while(t--) {
        int n;scanf("%d",&n);
        ll aa=0,bb=0,cc=0;
        for(int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
            if(a[i]) aa+=fib[i];
        }
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            scanf("%d",&b[i]);
            if(b[i]) bb+=fib[i];
        }
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            scanf("%d",&c[i]);
            if(c[i]) cc+=fib[i];
        }

        for(int i=1;i<=n;++i){
            if(c[i]==0){
                if(cc+fib[i]==aa*bb) {cout<<i<<endl;break;}
            }
        }
    }
}