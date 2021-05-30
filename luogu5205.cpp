// 多项式开根

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch = getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int P = 998244353;

inline int qpow(int x,int y){int res(1);while(y){if(y&1) res = 1ll*res*x%P;x = 1ll*x*x%P;y>>=1;}return res;}

int rev[MAXN<<2];

void change(int y[],int len){
    for(int i=0;i<len;++i){
        rev[i] = rev[i>>1]>>1;
        if(i&1) rev[i] |= len>>1;
    }
    for(int i=0;i<len;++i)
        if(i<rev[i]) swap(y[i],y[rev[i]]);
}

void ntt(int y[],int len,int on){
    change(y,len);
    for(int h=2;h<=len;h<<=1){
        int gn = qpow(3,(P-1)/h);
        for(int j=0;j<len;j+=h){
            int g = 1;
            for(int k=j;k<j+h/2;++k){
                int u = y[k];
                int t = 1ll*g*y[k+h/2]%P;
                y[k] = (u+t)%P;
                y[k+h/2] = (u-t+P)%P;
                g = 1ll*g*gn%P;
            }
        }
    }
    if(on==-1) {
        reverse(y+1,y+len);
        register int inv = qpow(len,P-2);
        for(int i=0;i<len;++i) y[i] = 1ll*y[i]*inv%P;
    }
}

static int sqrt_t[MAXN<<2],inv_t[MAXN<<2];
int invf[MAXN<<2];
int inv_two;

void getinv(int f[],int g[],int n){
    // 递归:把两个n/2的合并成一个n的
    if(n==1) {f[0] = qpow(g[0],P-2);return;}
    getinv(f,g,(n+1)>>1);
    int len(1);
    while(len<n<<1) len<<=1;
    copy(g,g+n,inv_t);
    fill(inv_t+n,inv_t+len,0);

    ntt(f,len,1);
    ntt(inv_t,len,1);
    for(int i=0;i<len;++i){
        f[i] = 1ll*f[i]*(2-1ll*f[i]*inv_t[i]%P+P)%P;
    }
    ntt(f,len,-1);
    fill(f+n,f+len,0);  // 取模
}

void solve(int f[],int g[],int n){
    // 递归:把两个n/2的合并成一个n的
    if(n==1) {f[0] = 1;return;} // 不需要二次剩余因为题目保证了a0=1
    solve(f,g,(n+1)>>1);
    int len(1);
    while(len<n<<1) len<<=1;
    copy(g,g+n,sqrt_t);
    fill(sqrt_t+n,sqrt_t+len,0);
    fill(invf,invf+len,0);
    getinv(invf,f,n);

    ntt(f,len,1);
    ntt(invf,len,1);
    ntt(sqrt_t,len,1);

    for(int i=0;i<len;++i){
        f[i] = (1ll*inv_two*f[i]%P+1ll*inv_two*invf[i]%P*sqrt_t[i]%P)%P;
    }
    ntt(f,len,-1);
    fill(f+n,f+len,0);  // 取模
}


int f[MAXN<<2],g[MAXN<<2];

int main(){
    int n=read();
    for(int i=0;i<n;++i) g[i]=read();
    inv_two = qpow(2,P-2);
    solve(f,g,n);
    for(int i=0;i<n;++i)
        printf("%d%c",f[i],i==n-1?'\n':' ');
}
