#include<bits/stdc++.h>
using namespace std;
int b[4];
int main(){
    int a1,a2;cin>>b[1]>>b[2]>>b[3]>>b[4]>>a1>>a2;
    int flg = 0,mx = 0,pos = 0;
    for(int i=1;i<=4;++i) mx = max(b[i],mx);
    for(int i=1;i<=4;++i) if(b[i]<a1||mx-b[i]>a2){
        flg++,pos = i;
    }
    if(flg==1) printf("Warning: please check #%d!\n",pos);
    else if(flg) printf("Warning: please check all the tires!\n");
    else printf("Normal\n");
}
