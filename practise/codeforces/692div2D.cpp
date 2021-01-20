#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;int x,y;cin>>s>>x>>y;
    int n = s.length(),c=y<x;
    if(!c) swap(x,y);
    // now that x>=y. if c==1, 10 is better, if c==0, 01 is better

    ll sm = 0,t = 0;
    for(int i=0;i<n;++i){
        // means 1 if 10 is better, means 0 if 01 is better
        if(s[i]=='0'+c) sm += (i-t)*x,t++; // rest in the prefix
        else sm += t*y;
        // ?s are placed with the one better in latter.
    }
    // now t means the number of the one better in front in the array
    ll ans = sm;
    for(int i=0;i<n;++i){
        if(s[i]!='?') continue;
        // we modify the prefix in ?s to the one better in former.
        ans = min(ans,sm += (i-t)*x + (n-1-t-i)*y);
        t++;
    }
    cout<<ans<<endl;
}