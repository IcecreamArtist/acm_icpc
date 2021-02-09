//
// Created by Artis on 2021/1/24.
//
#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef complex<double> E;
int n,m;
const double pi = acos(-1);
E a[262145],b[262145],c[262145];
void FFT(E *x,int n,int type)
{
    if(n==1)return;
    E l[n>>1],r[n>>1];
    for(int i=0;i<n;i+=2)
        l[i>>1]=x[i],r[i>>1]=x[i+1];
    FFT(l,n>>1,type);FFT(r,n>>1,type);
    E wn(cos(2*pi/n),sin(type*2*pi/n)),w(1,0);
    for(int i=0;i<n>>1;i++,w*=wn)
        x[i]=l[i]+w*r[i],x[i+(n>>1)]=l[i]-w*r[i];
}
const int maxn = 5e4+10;
int nu,nm,nl;
int xu[maxn],xm[maxn],xl[maxn];
int main()
{
    scanf("%d",&nu);
    fo(i,1,nu)scanf("%d",xu+i);
    scanf("%d",&nm);
    fo(i,1,nm)scanf("%d",xm+i);
    scanf("%d",&nl);
    fo(i,1,nl)scanf("%d",xl+i);

    fo(i,1,nu)a[xu[i]+30000]+=1;
    n=60000;
    fo(i,1,nl)b[xl[i]+30000]+=1;
    m=60000;


    m=n+m;for(n=1;n<=m;n<<=1);
    FFT(a,n,1);FFT(b,n,1);
    for(int i=0;i<=n;i++)a[i]=a[i]*b[i];
    FFT(a,n,-1);
    long long ans = 0;
    for(int i=1;i<=nm;i++)
        ans += (int)(a[xm[i]*2+30000].real()/n+0.5);
    printf("%lld\n",ans);
    return 0;
}

