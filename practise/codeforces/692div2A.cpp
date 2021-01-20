#include<bits/stdc++.h>
using namespace std;
char str[104];

void solve(){
    int n;scanf("%d",&n);
    scanf("%s",str+1);
    int pos = n;
    while(str[pos]==')') pos--;
    pos++;
    pos = n-pos+1;
    if(pos>n-pos) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}
