#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[100004],x[100004];

void solve(){
    //cout<<"test case: "<<++cas<<endl;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%lld%lld",&t[i],&x[i]);
    int ans = 0;
    ll curs=0,curt=0,st=0; // 当前正在进行的运动的开始位置、终止位置和开始时间
    t[n+1] = 100000000000000;
    for(int i=1;i<=n;++i){
        if(t[i]-st>=abs(curt-curs)){
            // 进行新的运动
            st = t[i];
            curs = curt;
            curt = x[i];
        }
        // 判断是否能在下一段之中经过x[i]指定位置
        if(curt-curs>0){
            if(min(curs+t[i]-st,curt)<=x[i]&&min(curs+t[i+1]-st,curt)>=x[i]) {
                ans++;
                //cout<<"i== "<<i<<endl;
            }
        }else if(curt-curs<0){
            if(max(curs-t[i]+st,curt)>=x[i]&&max(curs-t[i+1]+st,curt)<=x[i]) {
                ans++;
                //cout<<"i== "<<i<<endl;
            }
        }else{
            if(curt==x[i]){
                ans++;
               // cout<<"i== "<<i<<endl;
            }
        }
    }

    cout<<ans<<endl;
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}
