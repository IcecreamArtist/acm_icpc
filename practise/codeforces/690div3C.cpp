#include<bits/stdc++.h>
using namespace std;
int num = 0;
int vis[11];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x;scanf("%d",&x);
        memset(vis,0,sizeof(vis));
        for(int i=9;i>=1;--i){
            if(x>=i&&!vis[i]){
                vis[i] = 1;
                num++;
                x-=i;
            }
        }
        if(x==0){
            for(int i=1;i<=9;++i)
                if(vis[i]) cout<<i;
                cout<<endl;
        }else cout<<"-1"<<endl;
    }
}