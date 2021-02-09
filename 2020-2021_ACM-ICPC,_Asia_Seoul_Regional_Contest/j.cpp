#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 504;

bitset<maxn> a[maxn];  // linear basis
vector<int> v[maxn];
vector<int> vv;

int insert(int n,bitset<maxn> p,int id,int opt){
    for(int j=n-1;j>=0;--j){
        if(!p[j]) continue;
        if(a[j]!=0) {
            if(!opt) v[j].push_back(id);
            if(opt) vv.push_back(j);
            p^=a[j];
        }
        else {
            if(opt){return -1;}
            for(int k=0;k<j;++k) if(p[k]) p^=a[k];
            for(int k=j+1;k<maxn;++k) if(a[k][j]) a[k]^=p;
            a[j]=p;
            return 0;
        }
    }
}

vector<int> res[maxn];

int main(){
    int n;cin>>n;
    bitset<maxn> p;
    for(int i=1;i<=n;++i){
        p.reset();
        for(int j=0;j<n;++j){
            int tmp;scanf("%d",&tmp);
            if(tmp) p.set(j);
        }
        insert(n,p,i,0);
    }
    int flg=1;
    for(int i=0;i<n;++i){
        p.reset();p.set(i);
        vv.clear();
        if(insert(n,p,0,1)==-1) {
            cout<<"-1"<<endl;
            flg=0;
            return 0;
        }
        int len=vv.size();
        for(int j=0;j<len;++j){
            int num=vv[i];
            int len2=v[num].size();
            for(int k=0;k<len2;++k)
            res[i].push_back(v[num][j]);
        }
    }
    for(int i=0;i<n;++i){
        unique(res[i].begin(),res[i].end());
        sort(res[i].begin(),res[i].end());
        for(int j=0;j<res[i].size();++j)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    // 如何输出是哪些组合呢？
}