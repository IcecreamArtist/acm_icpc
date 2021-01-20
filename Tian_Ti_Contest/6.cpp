#include<bits/stdc++.h>
using namespace std;
string s = "chi1 huo3 guo1";


int main(){
    string t;
    int tot = 0,fnum = 0,num = 0;
    while(getline(cin,t)){
        int len = t.length();
        if(t[0]=='.'&&len==1) break;
        tot++;
        if(len<14) continue;
        for(int i=0;i<len;++i){
            if(len-i<14) break;
            int flg = 0;
            for(int j=i;j<i+14;++j){
                if(s[j-i]!=t[j]) {flg=1;break;}
            }
            if(!flg){
                if(!fnum) fnum = tot;
                num++;
                break;
            }
        }
    }
    if(fnum==0) printf("%d\n-_-#\n",tot);
    else printf("%d\n%d %d\n",tot,fnum,num);
}