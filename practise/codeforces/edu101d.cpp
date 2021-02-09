//
// Created by Artis on 2021/1/24.
//

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>v;

void solve(int n){
    if(n<=2) return;
    int sqn=(int)sqrt(n);
    if(sqn*sqn<n) sqn++;
    for(int i=sqn+1;i<=n-1;++i)
        v.push_back(make_pair(i,i+1));
    v.push_back(make_pair(n,sqn));
    v.push_back(make_pair(n,sqn));
    solve(sqn);
}

int main(){
    int t;cin>>t;
    while(t--){
        v.clear();
        int n;cin>>n;
        solve(n);
        cout<<v.size()<<endl;
        for(auto i:v)
            cout<<i.first<<" "<<i.second<<endl;
    }
}