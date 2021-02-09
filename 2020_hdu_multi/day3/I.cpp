#include<bits/stdc++.h>
using namespace std;

bool test(string s){
    stack<char>st;
    int len=s.length();
    for(int i=0;i<len;++i){
        if(s[i]=='(') st.push('(');
        if(s[i]==')') {
            if(st.empty()) return 0;
            char ch=st.top();st.pop();
            if(ch!='(') return 0;
        }
    }
    if(!st.empty()) return 0;
    return 1;
}

void solve(){
    string s;cin>>s;
    int len=s.length();
    string nos="";
    int cntl=0,cntr=0;
    for(int i=0;i<len;++i){
        if(s[i]!='*') nos+=s[i];
        if(s[i]=='(') cntl++;
        if(s[i]==')') cntr++;
    }
    if(test(nos)) {
        cout<<nos<<endl;
        return;
    }
    string now="";
    if(cntl>cntr){
        int num=cntl-cntr,nowcnt=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<len;i++){
            if(nowcnt<num&&s[i]=='*'){
                now+=')';
                nowcnt++;
            }else if(s[i]=='*'){

            }
            if(s[i]==')') now+=')';
            if(s[i]=='(') now+='(';
        }
        reverse(now.begin(),now.end());
        if(test(now)) cout<<now<<endl;
        else cout<<"No solution!"<<endl;
    }else if(cntr>cntl){
        int num=cntr-cntl,nowcnt=0;
        for(int i=0;i<len;++i){
            if(nowcnt<num&&s[i]=='*'){
                now+='(';
                nowcnt++;
            }
            if(s[i]==')') now+=')';
            if(s[i]=='(') now+='(';
        }
        if(test(now)) cout<<now<<endl;
        else cout<<"No solution!"<<endl;
    }else {
        cout<<"No solution!"<<endl;
        return;
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--) solve();
}