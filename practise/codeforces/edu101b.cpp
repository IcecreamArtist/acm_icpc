#include<bits/stdc++.h>
using namespace std;

int a[102],b[102];

vector<int> solve(int a[],int n){
    vector<int>tmp;
    for(int i=1;i<=n;++i){
        if(a[i]>=0) {
            tmp.push_back(a[i]);
            continue;
        }
        int t=a[i];
        while(t<0&&i+1<=n){
            ++i;
            t+=a[i];
        }
        tmp.push_back(t);
    }
    return tmp;
}
vector<int>na,nb;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n;
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        cin>>m;for(int i=1;i<=m;++i) scanf("%d",&b[i]);
        na=solve(a,n);
        nb=solve(b,m);
       // for(int i=0;i<na.size();++i) cout<<na[i]<<" ";
       // cout<<endl;
       // for(int i=0;i<nb.size();++i) cout<<nb[i]<<" ";
       // cout<<endl;
        int i=0,j=0;
        int ans=0,pre=0;
        while(i<na.size()&&j<nb.size()){
            if(na[i]>nb[j]) pre+=na[i],ans=max(ans,pre),i++;
            else pre+=nb[j],ans=max(ans,pre),j++;
        }
        while(i<na.size()) pre+=na[i],ans=max(ans,pre),i++;
        while(j<nb.size()) pre+=nb[j],ans=max(ans,pre),j++;
        cout<<ans<<endl;
    }
}
