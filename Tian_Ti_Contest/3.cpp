
#include<bits/stdc++.h>

using namespace std;

int main(){
    double a1,a2;
    int opt;cin>>a1>>opt>>a2;
    if(opt==0){
        double ans = a1*2.455;
        printf("%.2f ",ans);
        if(ans/a2>=1) cout<<"T_T"<<endl;
        else cout<<"^_^"<<endl;
    }
    else {
        double ans = a1*1.26;
        printf("%.2f ",ans);
        if(ans/a2>=1) cout<<"T_T"<<endl;
        else cout<<"^_^"<<endl;
    }
}