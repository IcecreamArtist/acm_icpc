#include<bits/stdc++.h>
using namespace std;

int a[200003],b[200004];
vector<int>bot;

bool solve(int k,int n){
    for(int i=0;i<bot.size();++i){
        int j;
        for(j=i-1;j>1&&(!b[j]);j--){
            b[j]=min(b[j+1]-1+k,a[j]+k-1);
            if(b[j]<a[j]) return 0;
        }
        //cout<<j+1<<endl;
        if(b[j+1]+k<=b[j]) return 0;
        for(j=i+1;j<n&&(!b[j]);++j){
            b[i]=min(b[j-1]-1+k,a[j]+k-1);
            if(b[j]<a[j]) return 0;
        }
        if(b[j-1]+k<=b[j]) return 0;
    }
    return 1;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
//        if(n==2){
//            if((a[1]+k<=a[2])||(a[2]+k<=a[1])) cout<<"NO"<<endl;
//            else cout<<"YES"<<endl;
//            continue;
//        }
        memset(b,0,sizeof(b));
        b[1]=a[1],b[n]=a[n];
        bot.clear();
        for(int i=2;i<n;++i){
            if(a[i-1]>=a[i]&&a[i]<=a[i+1]) {
                b[i]=a[i]+k-1;bot.push_back(i);
            }
            if(a[i-1]<=a[i]&&a[i]>=a[i+1]) b[i]=a[i];
        }
        // 定下来了顶和底
        if(a[1]<=a[2]) b[1]=a[1]+k-1,bot.push_back(1);
        if(a[n]<=a[n-1]) b[n]=a[n]+k-1,bot.push_back(n);
        if(solve(k,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=1;i<=n;++i) cout<<b[i]<<" ";
        cout<<endl;
    }
}