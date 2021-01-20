//
// Created by Lenovo on 2020/11/22.
//

#include <bits/stdc++.h>
const int N = 1e6+6;
const int MOD = 1e9+7;
typedef long long ll;
ll num[3];
char s[N];

int main(){
    scanf("%s",s+1);
    int len = strlen(s+1);
    for(int i=1;i<=len;++i){
        if(s[i]=='e'){
            num[0] += 1;
            num[0]%=MOD;
        }
        if(s[i]=='m'){
            num[1] += num[0];
            num[1]%=MOD;
        }
        if(s[i]=='t'){
            num[2] += num[1];
            num[2]%=MOD;
        }
    }
    printf("%lld\n",num[2]);
}