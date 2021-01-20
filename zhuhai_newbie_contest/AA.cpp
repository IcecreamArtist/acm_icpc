//
// Created by Lenovo on 2020/11/22.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 104;
int a[N];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        if(a[i]==1) {
            puts("NO");
            continue;
        }
        int sqrtn = (int)sqrt(a[i]+0.01);
        for(int j = 2;j<=sqrtn;++j){
            if(a[i]%j==0) {
                puts("NO");
                goto loop;
            }
        }
        puts("YES");
        loop:;
    }
}