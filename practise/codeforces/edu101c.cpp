#include<bits/stdc++.h>
using namespace std;
int h[200003];

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        for(int i=1;i<=n;++i) scanf("%d",&h[i]);
        int st=h[1],ed=h[1],flg=0;
        for(int i=2;i<=n;++i){
            st=max(st-k+1,h[i]);
            ed=min(ed+k-1,h[i]+k-1);
            if(st>ed) {
                flg=1;
                break;
            }
        }
        if(st!=h[n]) flg=1;
        if(flg) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}