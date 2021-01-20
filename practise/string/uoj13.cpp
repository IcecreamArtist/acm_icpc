# include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m,cnt = 1;
char s[N];
int f[N],fail[N],cha[N],nx[N][29];  // trie

int Insert(){
    scanf("%s",s+1);
    int len = strlen(s+1),x = 0;
    for(int i=1;i<=len;++i) {
        int ch = s[i] == '/'? 0:s[i]-'a'+1;
        if(!nx[x][ch]){
            nx[x][ch] = ++cnt;
            f[cnt] = x;
            cha[cnt] = s[i];
        }
        x = nx[x][ch];
        // 到达末尾
        if((s[i+1]==0||s[i+1]=='/')&&fail[x]) x = fail[x];
    }
    return x;
}

void print(int x){
    if(!x) return;
    print(f[x]);
    printf("%c",cha[x]?cha[x]:'/');
}

int main(){
    scanf("%d%d",&n,&m);
    nx[0][0] = nx[1][0] = 1; // 第一个节点设为空节点,第二个节点是"/"
    f[1] = 0;cha[1] = '/';
    while(n--) {
        int x = Insert(),y=Insert();
        fail[x] = y;
    }
    while(m--) {
        int x = Insert();
        print(x);puts("");
    }
}