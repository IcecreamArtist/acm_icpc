#include<bits/stdc++.h>
using namespace std;
int a[4][4];
int vis[10];
int res[30];
int main(){
    int px,py;
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            cin>>a[i][j];
            vis[a[i][j]]=1;
            if(a[i][j]==0){
                px=i,py=j;
            }
        }
    }
    for(int i=1;i<=9;++i) if(!vis[i]){a[px][py]=i;break;}
    for(int i=1;i<=3;++i) {
        cin>>px>>py;
        cout<<a[px][py]<<endl;
    }
    int c;cin>>c;
    {
        res[6] = 10000;
        res[7] = 36;
        res[8] = 720;
        res[9] = 360;
        res[10] = 80;
        res[11] = 252;
        res[12] = 108;
        res[13] = 72;
        res[14] = 54;
        res[15] = 180;
        res[16] = 72;
        res[17] = 180;
        res[18] = 119;
        res[19] = 36;
        res[20] = 306;
        res[21] = 1080;
        res[22] = 144;
        res[23] = 1800;
        res[24] = 3600;
    }
    int ans = 0;
    if(c<=3){
        for(int i=1;i<=3;++i) ans+=a[c][i];
    }
    else if(c>3&&c<=6){
        c-=3;
        for(int i=1;i<=3;++i) ans+=a[i][c];
    }
    else if(c==7){
        ans+=a[1][1]+a[2][2]+a[3][3];
    }
    else {
        ans+=a[3][1]+a[2][2]+a[1][3];
    }
    cout<<res[ans]<<endl;
}