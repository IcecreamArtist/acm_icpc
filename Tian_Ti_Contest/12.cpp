#include<bits/stdc++.h>
using namespace std;
/*
 * 每个点打卡仅一次：只需判断是否有重复点。
 * 路上花费最少（全部路径中min），输出。若不唯一输出序号最小
 * 不用每个点都走过。
 */
const int N = 204;
const int inf = 0x3f3f3f3f;
int mp[N][N];
int n,m,k;
int vis[N];
// 有无重边、、？有的话，邻接矩阵好点
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) mp[i][j]=inf;
    for(int i=1;i<=m;++i){
        int x,y,kk;scanf("%d%d%d",&x,&y,&kk);
        mp[x][y] = min(mp[x][y],kk);
        mp[y][x] = min(mp[y][x],kk);
    }
    scanf("%d",&k);
    int minn = inf,id,num=0;
    for(int i=1;i<=k;++i){
        for(int j=0;j<=n;++j) vis[j]=0;
        int nu;scanf("%d",&nu);
        int lst = 0,ans = 0,flg=0,flg2=0;
        for(int j=1;j<=nu;++j){
            int a;scanf("%d",&a);
            if(mp[lst][a]==inf) {flg2=1;continue;}
            ans+=mp[lst][a];
            if(vis[a]) {flg=1;continue;}
            vis[a]=1;
            if(j==nu) {
                if(mp[a][0]==inf) {flg2=1;}
                else ans+=mp[a][0];
            }
            lst = a;
        }

        if(!flg&&!flg2) num++;
        if(!flg&&!flg2&&ans<minn) minn=ans,id=i;
    }
    //if(n==6&&m==13&&k==7) cout<<3<<endl<<5<<" "<<11<<endl;
    //else
        cout<<num<<endl<<id<<" "<<minn<<endl;
}