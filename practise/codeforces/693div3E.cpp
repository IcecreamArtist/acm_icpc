#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> ans(n,-1);
    vector<array<int,3>> a;
    for(int i=1;i<=n;++i){
        int h,w,id=i;scanf("%d%d",&w,&h);
        if(w>h) swap(w,h);
        a.push_back({w,-h,id});
    }
    sort(a.begin(),a.end());
    int mn=0x7f7f7f7f,mnid=-1;
    for(auto &i:a){
        int h,id;
        h=-i[1],id=i[2];
        if(h>mn) ans[id-1]=mnid;
        if(h<mn) mn=h,mnid=id;
    }
    for(int& i:ans) cout<<i<<" ";
    cout<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();
}