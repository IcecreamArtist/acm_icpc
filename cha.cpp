#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[20];
int vis[103]; // Ã¿¸öÎ»ÖÃ×øÃ»×øÈË
int sum;
int flag;

int getpos(int i){
    if(i*2<x) return (x+1)/2-i;
    else return -1*(i-(x+1)/2);
}
void solve(int u){
    if(flag) return;
    if(u==n+1){
        if(sum==0) {
            flag=1;
            for(int i=1;i<=x;++i){
                cout<<a[vis[i]]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // position
    for(int i=1;i<=x;++i){
        if(i*2==x||vis[i]) continue;
        vis[i] = u;
        sum += a[u]*getpos(i);
        solve(u+1);
        vis[i] = 0;
        sum -= a[u]*getpos(i);
    }
}

int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    solve(1);
    if(flag) printf("Yes\n");
    else printf("No\n");
}