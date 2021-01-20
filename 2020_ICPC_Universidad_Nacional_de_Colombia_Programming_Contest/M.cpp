/*
 * 题意：s的子序列中，如果有ai的前缀，输出。如果没有，输出impossible
 * 思路：从后往前扫s，记录每个字母在每个位置之后最前出现的position
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char s[N<<1],a[N<<1];
int n;
int pos[N<<1][28]; // 记录当前位置

void solve(){
    int len = strlen(s+1);
    int nowlast[28];
    for(int i=0;i<26;++i) nowlast[i]=-1;
    for(int i=len;i>=0;--i){
        for(int j=0;j<26;++j) pos[i][j]=nowlast[j];
        nowlast[s[i]-'a']=i;
    }
}

int main(){
    scanf("%s",s+1);
    solve();
    scanf("%d",&n);
    while(n--){
        scanf("%s",a+1);
        int len = strlen(a+1),p = 0;  // 当前在s中所处的位置
        int len2=0;
        for(int i=1;i<=len;++i){
            p=pos[p][a[i]-'a'];
            if(p==-1) break;
            printf("%c",a[i]);
            len2++;
        }
        if(len2) puts("");else puts("IMPOSSIBLE");
    }
}