#include<bits/stdc++.h>

using namespace std;
int a[2003];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int k,l;scanf("%d%d",&k,&l);
        if(l>=2000){
            puts("-1");continue;
        }
        a[1]=-1;
        for(int i=2;i<=1999;++i) a[i] = (k+1999)/1998;
        a[1999]+=(k+1999)%1998;
        printf("1999\n");
        for(int i=1;i<=1999;++i) printf("%d ",a[i]);
        puts("");
    }
}

