//
// Created by acm on 2021/5/27.
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
#define dom 20101009
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
const int maxn = 1e7+4;
int mu[maxn],sum[maxn],pri[maxn],cnt;
bool vis[maxn];

void getmu(int mx){
    mu[1]=1;
    for(int i=2;i<=mx;++i){
        if(!vis[i]) pri[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&pri[j]*i<=mx;++j){
            vis[i*pri[j]] = true;
            if(i%pri[j]==0){
                mu[i*pri[j]] = 0;
                break;
            }
            mu[pri[j]*i]=-mu[i];
        }
    }
    for(int i=1;i<=mx;++i) sum[i] = sum[i-1]+i*i%dom*(mu[i]+dom)%dom, sum[i]%=dom;
}

int solve3(int n,int m){
    return (n+1)*n/2%dom*((m+1)*m/2%dom)%dom;
}

int solve2(int n,int m){
    int ans = 0;
    for(int d=1,j;d<=min(n,m);d=j+1){
        j=min(n/(n/d),m/(m/d));
        ans += (sum[j]-sum[d-1]+dom)%dom*solve3(n/d,m/d)%dom;
        ans%=dom;
       // cout<<solve3(n/d,m/d)<<" ";
    }
    return ans;
}

int solve(int n,int m){
    int ans = 0;
    for(int d=1,j;d<=min(n,m);d=j+1){
        j=min(n/(n/d),m/(m/d));
        ans += (d+j)*(j-d+1)/2%dom*solve2(n/d,m/d)%dom;
        ans %= dom;
    }
    return ans;
}

signed main() {
    fast;
    int n,m;cin>>n>>m;
    getmu(max(n,m));
    cout<<solve(n,m)<<endl;
    return 0;
}