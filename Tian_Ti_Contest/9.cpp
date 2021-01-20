#include<bits/stdc++.h>
using namespace std;
stack<int>s1;
stack<char>s2;

int main(){
    int n,a;cin>>n;char c;
    for(int i=1;i<=n;++i){
        cin>>a;s1.push(a);
    }
    for(int i=1;i<=n-1;++i){
        cin>>c;s2.push(c);
    }
    int flg = 0;
    while(!s2.empty()){
        int a1 = s1.top();s1.pop();
        int a2=s1.top();s1.pop();
        char op = s2.top();s2.pop();
        if(op=='/'&&a1==0){
            printf("ERROR: %d/0\n",a2);
            flg=1;
            break;
        }
        if(op=='+') a1 = a1+a2;
        if(op=='-') a1 = a2-a1;
        if(op=='*') a1 = a2*a1;
        if(op=='/') a1 = a2/a1;
        s1.push(a1);
    }
    if(!flg) cout<<s1.top()<<endl;
}
