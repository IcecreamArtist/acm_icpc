#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;

int a[maxn][maxn];
char s[100002];

int ord[4],val[4],res[4];
int ans[maxn][maxn];
// ord 表示坐标系的相对(I与C)变换(x,y,z),1代表x,2代表y,3代表z
// val 代表坐标系的绝对(RLDU)变换(x,y,z),记录在val数组中

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&a[i][j]);
    scanf("%s",s+1);
    ord[1]=1,ord[2]=2,ord[3]=3;
    val[1]=val[2]=val[3]=0;
    for(int i=1;i<=m;++i){
        if(s[i]=='R') val[ord[2]]++;
        if(s[i]=='L') val[ord[2]]--;
        if(s[i]=='D') val[ord[1]]++;
        if(s[i]=='U') val[ord[1]]--;
        if(s[i]=='I') swap(ord[2],ord[3]);
        if(s[i]=='C') swap(ord[1],ord[3]);
    }
    // 最后得出的，ord[]的val为起始i变换后成了哪个坐标轴、
    // val[ord[]]为此坐标轴的绝对改变量。
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=3;++k){
                // 即原先是k的，现在成为了1，那么res[k]就是
                // 到原点距离+1的绝对改变量。就是k的结局。
                if(ord[k]==1) res[k] = i+val[1];
                if(ord[k]==2) res[k] = j+val[2];
                if(ord[k]==3) res[k] = a[i][j]+val[3];
                res[k] = (res[k]%n+n)%n;
                if(res[k]==0) res[k]=n;
            }
            // i的结局   j的结局    val的结局。
            ans[res[1]][res[2]] = res[3];
        }
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cout<<ans[i][j]<<" \n"[j==n];
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}
