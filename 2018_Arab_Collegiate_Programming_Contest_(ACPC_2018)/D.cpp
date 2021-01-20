#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+6;
struct node{
    ll x,y;
}pt[maxn];
vector<ll>x,y;
ll mp[maxn][maxn];

void solve(){
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    memset(mp,0,sizeof(mp));
    memset(pt,0,sizeof(pt));
    x.clear(),y.clear();
    for(int i=1;i<=k;++i){
        ll xx,yy;
        scanf("%lld%lld",&xx,&yy);
        x.push_back(xx);y.push_back(yy);
        pt[i].y=yy,pt[i].x=xx;
    }
    x.push_back(n+1),y.push_back(m+1);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.resize(unique(x.begin(),x.end())-x.begin());
    y.resize(unique(y.begin(),y.end())-y.begin());
    for(int i=1;i<=k;++i){
        int xx = lower_bound(x.begin(),x.end(),pt[i].x)-x.begin()+1;
        int yy = lower_bound(y.begin(),y.end(),pt[i].y)-y.begin()+1;
        mp[xx][yy]++;
    }
    for(int i=1;i<=k+1;++i){
        for(int j=1;j<=k+1;++j){
            mp[i][j]=mp[i][j]+mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
        }
    }
    ll ans = 0;
    int szx=x.size(),szy=y.size();

    for(int i=0;i<szx-1;++i){
        for(int j=0;j<szy-1;++j){
            if(mp[i+1][j+1]&1){
                ll m1,m2;
                m1=(x[i+1]-x[i]);
                m2=(y[j+1]-y[j]);
                ans += m1*m2;
            }
        }
    }
    cout<<ans<<" "<<(ll)m*n-ans<<endl;
}
/*
 * 3
3 3 0
3 3 1
2 2
5 5 5
1 5
2 1
3 3
4 2
5 4
 */
int main(){
    //freopen("dull.in","r",stdin);
    int t;scanf("%d",&t);
    while(t--){
        solve();
    }
}