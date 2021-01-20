#include<bits/stdc++.h>
using namespace std;
int d,p,tot;  // number of person
int t[1003],s[1003];
map<string,int>last;
map<string,int>zk;

struct node{
    string name;
    string id;
    int t1,t2;
    int pre;
}per[30004];  // all person that are valid

struct node2{
    string name,id;
    int pre;
}per2[30004];

bool cmp1(node a,node b){
    if(a.t1==b.t1&&a.t2==b.t2) return a.pre<b.pre;
    if(a.t1==b.t1) return a.t2<b.t2;
    return a.t1<b.t1;
}

bool cmp2(node2 a,node2 b){
    return a.pre<b.pre;
}

bool check(string s){
    for(int i=0;i<18;++i) if(!isdigit(s[i])) return false;
    return true;
}

int main(){
    scanf("%d%d",&d,&p);
    for(int i=1;i<=d;++i){
        scanf("%d%d",&t[i],&s[i]);
        int st = tot; // 待会特判有没有合法人
        for(int j=1;j<=t[i];++j){
            string name,id;int ish,hh,mm;
            cin>>name>>id;
            scanf("%d %d:%d",&ish,&hh,&mm);
            // 待会check测试一下字母会不会给过
            if(id.length()==18&&check(id)) {
                if(zk.find(id)==zk.end()) zk[id]=ish;
                if(zk[id]==0&&ish==1) zk[id]=1;
                if(last.find(id)==last.end()||i-last[id]>p){
                    tot++;
                    per[tot] = {name,id,hh,mm,tot};
                }
            }
        }
        if(st==tot) continue;
        sort(per+st+1,per+tot+1,cmp1);
        for(int j=1;j<=min(s[i],tot-st);++j){
            last[per[st+j].id] = i;
            cout<<per[st+j].name<<" "<<per[st+j].id<<endl;
        }
    }
    // 按照申请记录中出现的先后顺序
    int tot2 = 0;
    for(int i=1;i<=tot;++i){
        if(zk[per[i].id]==1){
            per2[++tot2] = {per[i].name,per[i].id,per[i].pre};
            zk[per[i].id]=2;
        }
    }
    sort(per2+1,per2+1+tot2,cmp2);
    for(int i=1;i<=tot2;++i) cout<<per2[i].name<<" "<<per2[i].id<<endl;
}

