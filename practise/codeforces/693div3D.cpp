#include<bits/stdc++.h>
using namespace std;

vector<int>a;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        a.clear();
        for(int i=0;i<n;++i){int u;scanf("%d",&u);a.push_back(u);}
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        long long ans=0;
        for(int i=0;i<n;++i){
            if(a[i]&1&&i&1) ans-=a[i];
            if(!(a[i]&1)&&!(i&1)) ans+=a[i];
        }
        if(ans>0) cout<<"Alice"<<endl;
        else if(ans==0) cout<<"Tie"<<endl;
        else cout<<"Bob"<<endl;
    }
}