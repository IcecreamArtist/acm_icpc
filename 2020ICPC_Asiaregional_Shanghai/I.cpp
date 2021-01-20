#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-12;
double a[505],b[505];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    // init
    double init = 0;
    for(int i=1;i<m;++i){
        if(PI*i>2.0*m) init += 2.0;
        else init += PI*i/m;
    }
    init *= 2.0,init += 2.0;
    a[1] = init,b[1] = init;
    for(int i=2;i<=n;++i){
        b[i] = b[1] * i;
        a[i] = a[i-1] + b[i] + 2.0*m*(i-1);
    }
    double ans = 0;
    for(int i=1;i<=n;++i){
        ans += 1.0*m*b[i] + 2.0*m*(a[i]-b[i]);
        if(m>1) ans += 2.0*m*i;
    }
    printf("%.10lf\n",ans);
}