#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void exgcd(int a,int b,int &x,int &y){
    if(!b) {x=1,y=0;return;}
    exgcd(b,a%b,y,x);
    y-=x*(a/b);
}

int main(){
    int a,b;scanf("%d%d",&a,&b);
    int x,y;
    exgcd(a,b,x,y);
    printf("%lld\n",(x+b)%b);
}