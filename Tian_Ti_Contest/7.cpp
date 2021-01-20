#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    int tot = 1;
    for(int i=1;i<=n;++i) tot*=2;
    for(int i=1;i<=m;++i){
        int l = 1,r = tot;
        string s;cin>>s;
        int len = s.length();
        for(int j=0;j<len-1;++j){
            if(s[j]=='y') r = (l+r)>>1;
            else l = (l+r)>>1|1;
        }
        if(s[len-1]=='y') cout<<l<<endl;
        else cout<<r<<endl;
    }
}