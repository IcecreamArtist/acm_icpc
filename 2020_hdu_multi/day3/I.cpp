#include<bits/stdc++.h>
using namespace std;

string s;

void solve(){
    cin>>s;
    int len=s.length();
    stack<char>s1;
    queue<char>s2;
    for(int i=len-1;i>=0;--i){
        if(s[i]==')') s1.push(i);
        else if(s[i]=='('){
            if(!s1.empty()) s1.pop();
            else s2.push(i);
        }
    }
    for(int i=len-1;i>=0;--i){
        if(s2.empty()) break;
        if(s[i]=='*')
            if(i>s2.front()) s[i]=')',s2.pop();
    }
    for(int i=0;i<len;++i){
        if(s1.empty()) break;
        if(s[i]=='*')
            if(i<s1.top()) s[i]='(',s1.pop();
    }
    if(!s1.empty()||!s2.empty()) cout<<"No solution!"<<endl;
    else {
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        cout<<s<<endl;
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}