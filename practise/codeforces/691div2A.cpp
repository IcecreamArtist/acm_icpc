#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1003],b[1003];
char aa[1004],bb[1003];
void solve(){
    int n;scanf("%d",&n);
    scanf("%s",aa);
    scanf("%s",bb);
    for(int i=1;i<=n;++i){
        a[i] = aa[i-1]-'0';
    }
    for(int i=1;i<=n;++i){
        b[i] = bb[i-1]-'0';
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;++i){
        if(a[i]>b[i]) ans1++;
        else if(b[i]>a[i]) ans2++;
    }
    if(ans1>ans2) cout<<"RED"<<endl;
    else if(ans1<ans2) cout<<"BLUE"<<endl;
    else puts("EQUAL");
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}
