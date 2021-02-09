# include <bits/stdc++.h>
# define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 1e5+10;
char A[maxn],B[30];
int nxt[maxn][26];
int n,m,q;
int f[25][25];
const int inf=0x7f7f7f7f;
void solve(){
    scanf("%s",A+1);
    scanf("%s",B+1);
    n = strlen(A+1), m = strlen(B+1);
    fo(i,0,26) nxt[n][i] = n+1;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<26;++j)
            nxt[i][j] = nxt[i+1][j];
        nxt[i][A[i+1]-'a']=i+1;
    }

    scanf("%d",&q);
    while(q--){
        int l,r; scanf("%d%d",&l,&r);
        memset(f,inf,sizeof(f));
        // 已走到B串的第i个，已匹配到j个字母的，于A串中最前的位置。
        f[1][1] = nxt[l-1][B[1]-'a'];
        for(int i=0;i<=m;++i) f[i][0]=l-1;
        fo(i,2,m){  // 循环B串的字母
            fo(j,1,i){  // 已经匹配到的字母
                f[i][j] = f[i-1][j]; // 不配当前，则往后。
                // 如果前一个已经配到，则选当前，往后
                if(f[i-1][j-1] <= r){
                    f[i][j] = min(f[i][j],nxt[f[i-1][j-1]][B[i]-'a']);
                }
            }
        }
        int ans=0;
        for(int j=1;j<=m;++j) if(f[m][j]<=r) ans=j;
        printf("%d\n",(r-l+1) + m - 2*ans);
    }
}
/*
 * 1
youyouyou
uuu
1
4 5

1
youyouyou
uuu
1
5 6

ans:3
correct:5
 */
int main(){
    int T; scanf("%d",&T);
    while(T--)solve();
    return 0;
}

