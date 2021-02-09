#include<bits/stdc++.h>
using namespace std;
const int maxn = 53;
int mp[maxn][maxn];
int mx,n;

int point[maxn];

bool isclique(int num,int p){
    for(int i=1;i<=num;++i)
        if(!mp[point[i]][p])
            return 0;
    return 1;
}

void dfs(int num,int p){
    for(int i=p;i<=n;++i){
        if(isclique(num,i)){
            point[num+1]=i;
            dfs(num+1,i+1);
        }
    }
    mx=max(mx,num);
}

int main(){
    while(~scanf("%d",&n),n){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d",&mp[i][j]);
        mx=0;
        dfs(0,1);
        cout<<mx<<endl;
    }
}