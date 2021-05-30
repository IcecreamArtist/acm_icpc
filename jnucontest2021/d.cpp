#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))

const int maxn = 1e5+5;
int a[maxn],c[maxn];
int dp[100003];
int L[maxn],ori[maxn];

int discretize(int n){
    for(int i=0;i<n;++i) c[i] = a[i];
    sort(c,c+n);
    int len = unique(c,c+n)-c;
    int maxx = 0;
    for(int i=0;i<n;++i){
        L[i] = lower_bound(c,c+len,a[i])-c+1;
        maxx = max(maxx,L[i]);
        ori[L[i]] = a[i];
    }
    return maxx;
}

int tree[maxn];

void add(int x,int d){
    while(x<=n){
        tree[x] = max(tree[x],d);
        x += lowbit(x);
    }
}

int findmaxdp(int x){
    int ret = 0;
    while(x>0){
        ret = max(ret,tree[x]);
        x -= lowbit(x);
    }
    return ret;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    int maxx = discretize(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<=m;++j){
            dp[j] = max(dp[j], findmaxdp(j-1) + a[i]);
            add(j,L[i]);
        }
    }
    if(dp[j]!=0){
        cout<<dp[j]<<endl;
    }else cout<<-1<<endl;
}
