//
// Created by Artis on 2021/1/27.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 17;
int n,d;
int MOD;
struct mat{
    ll a[sz][sz];
    inline mat() {memset(a,0,sizeof(a));}
    inline mat operator-(const mat& T) const{
        mat res;
        for(int i=0;i<d;++i)
            for(int j=0;j<d;++j)
                res.a[i][j]=(a[i][j]-T.a[i][j]+MOD)%MOD;
        return res;
    }
    inline mat operator+(const mat& T) const{
        mat res;
        for(int i=0;i<d;++i)
            for(int j=0;j<d;++j)
                res.a[i][j]=(a[i][j]+T.a[i][j])%MOD;
        return res;
    }
    inline mat operator*(const mat& T) const{
        mat res;
        int r;
        for(int i=0;i<d;++i)
            for(int k=0;k<d;++k){
                r=a[i][k];
                for(int j=0;j<d;++j)
                    res.a[i][j]+=T.a[k][j]*r,res.a[i][j]%=MOD;
            }
        return res;
    }
    inline mat operator^(ll x) const{
        mat res,bas;
        for(int i=0;i<d;++i) res.a[i][i]=1;
        for(int i=0;i<d;++i)
            for(int j=0;j<d;++j) bas.a[i][j]=a[i][j]%MOD;
        while(x){
            if(x&1) res=res*bas;
            bas=bas*bas;
            x>>=1;
        }
        return res;
    }
};

int main(){
    while(~scanf("%d%d%d",&d,&n,&MOD),(d||n||MOD)){
        mat a;
        for(int i=0;i<d;++i){
            int tmp;scanf("%d",&tmp);
            a.a[0][i]=tmp;
        }
        for(int i=1;i<d;++i) a.a[i][i-1]=1;
        mat x;
        for(int i=d-1;i>=0;--i) {
            int tmp;scanf("%d",&tmp);
            x.a[i][0]=tmp;
        }
        if(n<=d){
            cout<<x.a[n-1][0]<<endl;
            continue;
        }
        a=a^(n-1);
        x=a*x;
        cout<<x.a[d-1][0]<<endl;
    }
}
