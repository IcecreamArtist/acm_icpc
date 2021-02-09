//
// Created by Artis on 2021/1/24.
//

#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    for(int i=1;i<=6;++i) scanf("%d",&a[i]);
    for(int i=1;i<=6;++i) scanf("%d",&b[i]);
    int ans=0;
    for(int i=1;i<=6;++i){
        for(int j=1;j<=6;++j){
            if(a[i]>b[j]) ans++;
        }
    }
    int g=gcd(ans,36);
    cout<<ans/g<<"/"<<36/g<<endl;
}