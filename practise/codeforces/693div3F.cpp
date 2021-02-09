#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    map<int,int>mp;
    for(int i=1;i<=m;++i){
        int r,c;scanf("%d%d",&r,&c);
        mp[c]|=1<<(r-1);
    }
    mp[1e9]=3;
    int ls=0,lspos=0;
    for(auto[a,b]:mp){
        int pos=(a+b)%2;
        if(ls){
            if(b==3||lspos==pos) {
                cout<<"no"<<endl;
                return;
            }else{
                ls=0;
            }
        }else{
            if(b!=3){
                ls=1;
                lspos=pos;
            }
        }
    }
    cout<<"yes"<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}