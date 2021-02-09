//
// Created by Artist on 2021/1/23.
//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int len=s.size();
        if(len&1) cout<<"NO"<<endl;
        else if(s[0]==')'||s[len-1]=='(') cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}