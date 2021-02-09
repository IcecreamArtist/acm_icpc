#include<bits/stdc++.h>
using namespace std;
// 哈希二：二进制->十进制哈希法。

int ceillog(int x){
    int y=0;
    while((1<<y)<x)
        y++;
    return y;
}

int main(){
    int q;cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int m=min(k,ceillog(n-k+2));
        // 只用判定这个长度即可。
        vector<int>used((1<<m),0);
        vector<int>back0(n,int(1e9)); // 对于每个字符串的每个位置，其后的0的位置。
        for(int i=n-1;i>=0;--i){
            if(s[i]==0) back0[i]=i;
            else if(i!=n-1) back0[i]=back0[i+1];
        }
        int d=k-m;// 不用判定的长度
        for(int i=0;i<n-k+1;++i){
            if(back0[i]-i<d) continue;
            int cur=0;
            for(int j=i+d;j<i+k;++j)
                cur=cur*2+s[j]-'0';
            used[((1<<m)-1)^cur]=1;
        }
        int ans=-1;
        for(int i=0;i<(1<<m);++i){
            if(used[i]==0){ans=i;break;}
        }
        if(ans==-1) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            string res(d,'0');
            string res2;
            for(int i=0;i<m;++i){
                res2.push_back('0'+(ans%2));
                ans/=2;
            }
            reverse(res2.begin(),res2.end());
            res+=res2;
            cout<<res<<endl;
        }
    }
}