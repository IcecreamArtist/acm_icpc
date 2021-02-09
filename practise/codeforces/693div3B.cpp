//
// Created by Artis on 2021/1/26.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;++i) {
            int tmp;cin>>tmp;
            if(tmp==1) cnt1++;
            else cnt2++;
        }
        int mid=(cnt1+cnt2*2);
        if(mid&1){cout<<"no"<<endl;continue;}
        mid>>=1;
        if(mid&1){
            if(cnt1>1) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }else cout<<"yes"<<endl;
    }
}
