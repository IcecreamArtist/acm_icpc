#include<stdio.h>
#include<math.h>
#define min(a,b) ((a<b)?a:b)
#include<bits/stdc++.h>

using namespace std;

double getA(long long a,long long b,long long c){
    double coss = (1.0*b*b+1.0*c*c-1.0*a*a)/(2.0*(b)*(c));
    return acos(coss);
}

double solve(long long r1,long long r2,long long r3){
    double a = getA(r2+r3,r3+r1,r1+r2);
    double b = getA(r3+r1,r1+r2,r2+r3);
    double c = acos(-1)-a-b;
    //double ans = ( (1.0+(1.0*r2/1.0*r1))*(2*acos(-1)-2.0*b) + (1.0+(1.0*r3/1.0*r1))*(2*acos(-1)-2.0*c)  )/(2.0*acos(-1));
    double ans=(1.0+1.0*r2/(1.0*r1))*(1-b/acos(-1)) + (1.0+1.0*r3/(1.0*r1))*(1-c/acos(-1));
    //std::cout<<(1.0+1.0*r2/(1.0*r1))<<" "<<(1-b/acos(-1)) <<" "<< (1.0+1.0*r3/(1.0*r1))<<" "<<(1-c/acos(-1))<<endl;
    return ans;
}

int main() {
    int t;scanf("%d",&t);
    while(t--){
        long long r1,r2,r3;scanf("%lld%lld%lld",&r1,&r2,&r3);
        double ans = solve(r1,r2,r3);
        ans = min(ans,solve(r2,r1,r3));
        ans = min(ans,solve(r3,r1,r2));
        //cout<<solve(r1,r2,r3)<<" "<<solve(r2,r1,r3)<<" "<<solve(r3,r1,r2)<<endl;
        printf("%.11lf\n",ans);
    }
    return 0;
}