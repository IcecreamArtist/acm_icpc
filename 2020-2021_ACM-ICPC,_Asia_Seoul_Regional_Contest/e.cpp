#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e6+4;

int d[maxn];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)scanf("%d",&d[i]);
    for(int i=1;i<n;++i){
        if(d[i]>1) {cout<<"NO"<<endl;return 0;}
        if(d[i]) {
            if(d[i+1]) d[i+1]--;
            else d[i+1]++;
        }
    }
    if(d[n]==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}