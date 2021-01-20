//
// Created by Artis on 2020/11/21.
//

#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main(){
    int n;scanf("%d",&n);
    int mx = -1000000004;
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        if(i!=1) mx = max(mx,a[i]-a[i-1]);
    }
    printf("%d\n",mx);
}