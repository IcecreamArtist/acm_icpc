/*
 * 题意：四个操作，二维平面，有点权，加点、删点，查找某点周围距离\sqrt{k}的点权求和输出、查找并修改某点周围距离
 * \sqrt{k}的点点权加w。case1e3，初始点数n1e5，操作数m1e5，要求在线，k1e7，xyw6e3。
 * 思路：（暴力）观察到，k1e7非常小（作为距离的平方）。因此，暴力出1~1e7每个数为结果的可能的平方组合，存在一个vector之中。
 * 然后，对于给定点，和给定距离，遍历该距离的可能组合，对每个组合，都在四个方向上进行试探。
 */
#include <bits/stdc++.h>
using namespace std;
int t,cnt;
const int maxk = 1e7+6;
const int maxn = 1e5+5;
vector<pair<int,int>> G[maxk];
int vis1[10004];
int vis[6004][6004];
int val[6004][6004];
int px[maxn<<1],py[maxn<<1];
typedef long long ll;
ll ans,lastans;

int main(){
    scanf("%d",&t);
    for(int i=0;i<=1e4;++i){
        for(int j=0;j<=1e4;++j){
            if(i*i+j*j>1e7) break;
            if(i==j){
                if(vis1[i]) continue;
                else vis1[i]=1;
            }
            G[i*i+j*j].push_back(make_pair(i,j));
        }
    }
    for(int ca=1;ca<=t;++ca){
        printf("Case #%d:\n",ca);
        int n,m,opt,x,y;ll w,k;scanf("%d%d",&n,&m);
        lastans = cnt = 0;
        for(int i=1;i<=n;++i){
            scanf("%d%d%lld",&x,&y,&w);
            px[++cnt] = x,py[cnt] = y;
            vis[x][y] = 1,val[x][y] = w;
        }
        for(int c=1;c<=m;++c){
            scanf("%d%d%d",&opt,&x,&y);
            x = (x+lastans)%6000+1,y = (y+lastans)%6000+1;
            ans = 0;
            if(opt==1){
                scanf("%d",&w);
                px[++cnt] = x,py[cnt] = y;
                vis[x][y] = 1,val[x][y] = w;
            }
            if(opt==2){
                vis[x][y] = val[x][y] = 0;
            }
            if(opt==3){
                scanf("%lld%lld",&k,&w);
                for(auto d:G[k]){
                    int nx[3],ny[3];
                    nx[1] = x+d.first,nx[2] = x-d.first;
                    ny[1] = y+d.second,ny[2] = y-d.second;
                    for(int i=1;i<=2;++i){
                        if(nx[i]<1||nx[i]>6000) continue;
                        if(i==2&&nx[i]==nx[i-1]) continue;
                        for(int j=1;j<=2;++j){
                            if(ny[j]<1||ny[j]>6000) continue;
                            if(j==2&&ny[j]==ny[j-1]) continue;
                            if(vis[nx[i]][ny[j]]) val[nx[i]][ny[j]]+=w;
                        }
                    }
                }
            }
            if(opt==4){
                scanf("%lld",&k);
                for(auto d:G[k]){
                    int nx[3],ny[3];
                    nx[1] = x+d.first,nx[2] = x-d.first;
                    ny[1] = y+d.second,ny[2] = y-d.second;
                    for(int i=1;i<=2;++i){
                        if(nx[i]<1||nx[i]>6000) continue;
                        if(i==2&&nx[i]==nx[i-1]) continue;
                        for(int j=1;j<=2;++j){
                            if(ny[j]<1||ny[j]>6000) continue;
                            if(j==2&&ny[j]==ny[j-1]) continue;
                            if(vis[nx[i]][ny[j]]) ans+=val[nx[i]][ny[j]];
                        }
                    }
                }
                printf("%lld\n",ans);
                lastans = ans;
            }
        }
        for(int i=1;i<=cnt;++i) vis[px[i]][py[i]] = val[px[i]][py[i]] = 0;
    }
}