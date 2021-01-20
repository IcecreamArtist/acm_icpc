/*
题意：在两个串中分别取子串，拼凑在一起构成新串。要使得这个新串的字典序最大。
思路：分别找到两个串中的字典序最大子串。再试图将他们两个拼凑在一起。
难点：如果暴力找字典序最大子串，复杂度会很高，因此需要一点剪枝操作：即发现，如果当前字母等于出现过的最大字母，而当前上一个字母也等于这个字母。那当前位置必不可能是最大子串的起始位置。
注：这道题如果用char型数组代替string，运行时间可以减半。
*/
#include <bits/stdc++.h>
using namespace std;

int get_pos_of_min_string(string s,int len){
    int pos=-1,mx=0;
    for(int i=0;i<len;++i){
        if(s[i]>mx) mx=s[i],pos=i;
        else if(s[i]==mx&&s[i-1]!=mx){
            for(int j=1;j+i<len;++j){
                if(s[pos+j]>s[i+j]) break;
                if(s[pos+j]<s[i+j]){
                    mx=s[i];
                    pos=i;
                    break;
                }
            }
        }
    }
    return pos;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    int len1=s1.length(),len2=s2.length();
    char max1=0,max2=0;
    int pos1 = get_pos_of_min_string(s1,len1),pos2 = get_pos_of_min_string(s2,len2);
    printf("%c",s1[pos1]);
    for(int i=pos1+1;i<len1;++i){
        if(s1[i]<s2[pos2]) break;
        printf("%c",s1[i]);
    }
    for(int i=pos2;i<len2;++i) printf("%c",s2[i]);
    puts("");
}
