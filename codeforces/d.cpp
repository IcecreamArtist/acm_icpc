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

signed main() {
    fast;
    return 0;
}