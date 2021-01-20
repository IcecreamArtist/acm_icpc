#include<bits/stdc++.h>
using namespace std;
const int maxn = 104;
const int maxm = 1004;

map<string,int>mp[maxm];
bool tag[maxm];
int sz[maxm];

void dfs(int u){
    sz[u] = 0;
    if(!tag[u]) {
        sz[u] = 1;
        return;
    }
    for(auto v:mp[u]){
        dfs(v.second);
        sz[u]+=sz[v.second];
    }
}

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    int cnt = 0;
    getchar();
    for(int i=0;i<maxm;++i) mp[i].clear();
    for(int i=1;i<=n;++i){
        int now = 0;
        char ch = getchar();
        string s;
        while(1){
            while(ch!='/'&&ch!='\n'){
                s += ch;
                ch=getchar();
            }
            if(mp[now].find(s)==mp[now].end()) mp[now][s] = ++cnt;
            now = mp[now][s];
            tag[now] = 0;
            if(ch=='\n') {break;}
            s.clear();
            ch=getchar();
        }
    }
    for(int i=1;i<=m;++i){
        int now = 0;
        char ch = getchar();
        string s;
        while(1){
            while(ch!='/'&&ch!='\n'){
                s += ch;
                ch=getchar();
            }
            if(mp[now].find(s)==mp[now].end()) mp[now][s] = ++cnt;
            now = mp[now][s];
            tag[now] = 1;
            if(ch=='\n') {break;}
            s.clear();
            ch=getchar();
        }
    }
    tag[0] = 1;
    dfs(0);
    cout<<sz[0]<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
}