//
// Created by Artis on 2021/1/26.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int w,h,n;cin>>w>>h>>n;
        int cnt=0;
        while(w%2==0) w/=2,cnt++;
        while(h%2==0) h/=2,cnt++;
        if(((long long)1<<cnt)>=n) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
