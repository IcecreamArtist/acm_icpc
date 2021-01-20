#include<bits/stdc++.h>
using namespace std;
char a[204];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        scanf("%s",a+1);
        int num2 = 0,num20f = 0,num20l = 0,num202 = 0,num020 = 0,num0 = 0;
        if(n<4){
            cout<<"NO"<<endl;continue;
        }
        if(a[n]=='0'&&a[n-1]=='2'&&a[n-2]=='0'&&a[n-3]=='2'){
            cout<<"YES"<<endl;continue;
        }
        if(a[1]=='2'&&a[2]=='0'&&a[3]=='2'&&a[4]=='0'){
            cout<<"YES"<<endl;continue;
        }
        if(a[1]=='2') num2 = 1;
        if(num2&&a[2]=='0') num20f = 1;
        if(num20f&&a[3]=='2') num202 = 1;
        if(a[n]=='0') num0 = 1;
        if(num0&&a[n-1]=='2') num20l = 2;
        if(num20l&&a[n-2]=='0') num020 = 1;
        if(num2&&num020){
            cout<<"YES"<<endl;continue;
        }
        if(num20f&&num20l){
            cout<<"YES"<<endl;continue;
        }
        if(num202&&num0){
            cout<<"YES"<<endl;continue;
        }
        cout<<"NO"<<endl;
    }
}