#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;
int vis[N];
int a[N],pos[N],ans[N],cnt;

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]),pos[a[i]]=i;
    for(int i=1;i<=n;++i){
        for(int j=pos[i];j>i;--j){
            if(vis[j-1]) {puts("-1");return 0;}
            vis[j-1]=1;
            ans[++cnt]=j-1;
            swap(a[j],a[j-1]);
            pos[a[j]]=j;
            pos[a[j-1]]=j-1;
        }
    }
    for(int i=1;i<=n;++i){
        if(vis[i]!=1) {puts("-1");return 0;}
    }
    for(int i=1;i<=cnt;++i) cout<<ans[i]<<endl;
}