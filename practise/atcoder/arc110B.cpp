
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string str = "110";

bool check(string s){
    if(s[0]=='1'){
        if(s[1]=='1'){
            for(int i=0;i<n;++i){
                if(s[i]!=str[i%3]) return 0;
            }
        }else{
            for(int i=2;i<n;++i){
                if(s[i]!=str[(i-2)%3]) {
                    return 0;
                }
            }
        }
    }else{
        if(s[1]=='1'){
            for(int i=1;i<n;++i){
                if(s[i]!=str[(i-1)%3]) return 0;
            }
        }else return 0;
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    string s;cin>>s;
    ll ans = 1e10;
    if(n==1&&s[0]=='1') {cout<<ans*2<<endl;return 0;}
    if(n==1&&s[0]=='0') {cout<<ans<<endl;return 0;}
    bool y = check(s);
    if(y==0){cout<<0<<endl;return 0;}
    int pos = 0;
    if(s[n-1]=='1'&&s[n-2]=='1'){
        pos = 1;
    }else if(s[n-1]=='1'&&s[n-2]=='0') pos = 2;
    ans -= ((n+2+pos)/3-1);
    printf("%lld\n",ans);
}