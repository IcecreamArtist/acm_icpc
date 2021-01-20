#include<bits/stdc++.h>
using namespace std;
int a[3004];
typedef long long ll;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        ll mx = 0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            mx = max(mx,(ll)a[i]);
        }
        int num;
        while(1){
            ll sm = 0;int isf=1,pos;
            num = 0;
            int flg = 0;ll ne;
            for(int i=1;i<=n;++i){
                if(sm+a[i]==mx){
                    sm = 0;
                    if(isf) pos = i,isf=0;
                    num++;
                    if(i==n) flg=1;
                }
                else if(sm+a[i]>mx){
                    if(isf) pos = i-1;
                    break;
                }else{
                    sm += a[i];
                }
            }
            if(flg) break;
            mx = 0;
            for(int i=1;i<=pos+1;++i) mx+=a[i];
            //cout<<mx<<endl;
        }
        cout<<n-num<<endl;
    }
}
