/*
 * 考点：**数学** 组合数学 + 矩阵快速幂
 * 题意：有n个一样的色子，每个色子的面的数目一样，给出一个数字m。
 * m的含义：每个色子等于m的倍数的面被甩到的概率为0.
 * 求：所有色子甩出的总和等于m的倍数的概率。
 * 思路：容易想到题目只关乎是否是m的倍数，我们把所有面的序号都取模。
 * 得到数组num，记录每个色子中，面的序号取模后等于i的面的个数。
 * 这个概率的分母很容易：即每个色子除却m的倍数（num的i==0）的面之外的其他的面的总数，取n次方。
 * 假若现在只有两个色子，他们的和==0的情况个数newnum[0]=\sum{num[i]*num[m-i]}+num[0]*num[0]
 * 把两个色子得到的和的结果看成一个新的不同的色子。继续将这个色子与第三个色子进行求和。
 * 于是我们想到矩阵快速幂.
 * 矩阵具体的构造：见https://blog.csdn.net/bloom_er/article/details/108931558
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 204;
const int MOD = 1e9+7;
int n,k,m,num[N];

ll fp(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%MOD;x=x*x%MOD;y>>=1;}return ans;}

struct Matrix{
    ll a[210][210];
    Matrix(){memset(a,0,sizeof(a));}
    Matrix cal(const Matrix &A,int n){
        Matrix ans;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                for(int k=0;k<n;++k){
                    ans.a[i][j]+=a[i][k]*A.a[k][j]%MOD;
                    ans.a[i][j]%=MOD;
                }
        return ans;
    }
};

Matrix fastm(Matrix a,int m,int n){
    Matrix res;
    for(int i=0;i<m;++i) res.a[i][i]=1;
    while(n){
        if(n&1) res=res.cal(a,m);
        a=a.cal(a,m);
        n>>=1;
    }
    return res;
}

ll solve(){
    Matrix ans,pro;   // ans and product
    // draw the matrix
    for(int i=0;i<m;++i){
        int pos = 0;
        for(int j=i;j>=0;--j) pro.a[pos++][i]=num[j];
        for(int j=m-1;;--j){
            if(pos==m) break;
            pro.a[pos++][i]=num[j];
        }
    }
    ans = fastm(pro,m,n);
    return ans.a[0][0];
}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<m;++i) num[i] = k/m;
    int tmp = k%m;
    for(int i=1;i<=tmp;++i) ++num[i];
    ll fm = 0;   // 分母 和 答案
    for(int i=1;i<m;++i) fm += num[i]; // 即一个色子除了%m==0的其余面的数目。
    fm=fp(fm,n);  // 所有色子搭配的总情况数（分母）
    printf("%lld\n",solve()*fp(fm,MOD-2)%MOD);
}