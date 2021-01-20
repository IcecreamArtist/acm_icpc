
#include<bits/stdc++.h>

using namespace std;
double a[1004];

int main(){
    int n;scanf("%d",&n);
    double sm = 0;
    for(int i=1;i<=n;++i) scanf("%lf",&a[i]),sm += 1.0/a[i];
    if(sm==0) printf("0.00\n");
    else sm/=n,printf("%.2lf\n",1.0/sm);
}