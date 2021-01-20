#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b,c;cin>>n>>a>>b>>c;
    ll ans,mod;
    if(a>b-c){
        if(n>=b){
            ans = (n-b)/(b-c);
            mod = (n-b)%(b-c)+b;
        }else{
            ans = 0;
            mod = n;
        }
        ans += mod/b;
        mod = mod%b+mod/b*c;
        ans += mod/a;
    }else{
        ans = n/a;
    }
    cout<<ans<<endl;
}