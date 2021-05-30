//
// Created by acm on 2021/5/29.
//

#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define mp(a, b) make_pair(a,b)
#define vi vector<int>
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define vp vector<pair<int,int> >
#define pb(a) push_back(a)
#define fr(i, n) for(i=0;i<n;i++)
#define rep(i, a, n) for(i=a;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define dom 998244353
#define sl(a) (int)a.length()
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define mini 2000000000000000000
#define time_taken 1.0 * clock() / CLOCKS_PER_SEC

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const long double pi = acos(-1);
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
//primes for hashing 937, 1013
template<typename T, typename U>
static inline void amin(T &x, U y) {
    if (y < x) x = y;
}

template<typename T, typename U>
static inline void amax(T &x, U y) {
    if (x < y) x = y;
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline int qpow(int x, int y) {
    int res(1);
    while (y) {
        if (y & 1) res = 1ll * res * x % dom;
        x = 1ll * x * x % dom;
        y >>= 1;
    }
    return res;
}

string s;
// 把原问题转化为线段树维护矩阵乘积
const int maxn = 6;

struct Matrix{
    int m[maxn][maxn];
    int isempty;
    Matrix(){
        memset(m,0,sizeof(m));
    }
    Matrix(int id){
        memset(m,0,sizeof(m));
        for(int i=1;i<=5;++i){
            m[i][i]=1;
        }
        m[id-1][id] = 1;
    }
};

Matrix basi[maxn] = {{0},{1},{2},{3},{4},{5}};
int idex[70];

Matrix Multi(Matrix a,Matrix b){
    Matrix res;
    int i,j,k;
    fr(i,maxn) fr(j,maxn) fr(k,maxn)
    res.m[i][j] = (res.m[i][j] + a.m[i][k]*b.m[k][j]);
    return res;
};

Matrix fastm(Matrix a,int n){
    Matrix res;
    int i;
    fr(i,maxn) res.m[i][i] = 1;
    while(n){
        if(n&1) res = Multi(res,a);
        a = Multi(a,a);
        n>>=1;
    }
    return res;
}

const int MAXN = 1e5+10;

Matrix sum[MAXN<<2],add[MAXN<<2];

void push_up(int rt){
    sum[rt] = Multi(sum[rt<<1],sum[rt<<1|1]);
}

void push_down(int rt,int m){
    if(!add[rt].isempty){
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = fastm(add[rt],(m-(m>>1)));
        sum[rt<<1|1] = fastm(add[rt],(m>>1));
        add[rt].isempty = 1;
    }
}

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

void build(int l,int r,int rt){
    add[rt].isempty = 1;
    if(l==r){
        sum[l] = basi[idex[s[l-1]-'A']];
        return;
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int a,int b,Matrix c,int l,int r,int rt){
    if(a<=l&&b>=r){
        sum[rt] = Multi(sum[rt],);
        return;
    }
    push_down(rt,r-l+1);
    int mid = (l+r)>>1;

}

signed main() {
    fast;
    int t;cin>>t;
    // 定义了位置
    idex['F'-'A'] = 1;
    idex['e'-'A'] = 2;
    idex['i'-'A'] = 3;
    idex['M'-'A'] = 4;
    idex['a'-'A'] = 5;
    while(t--){
        int n,q;cin>>n>>q;
        cin>>s;
        for(int i=1;i<=q;++i){
            int l,r;
            char x;
            cin>>l>>r>>x;

        }
    }
    return 0;
}