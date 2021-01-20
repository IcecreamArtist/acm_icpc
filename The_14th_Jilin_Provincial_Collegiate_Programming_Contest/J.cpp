/*
2
0
.OO
X.O
OXO
1
XXX
XXX
XXX

 */
# include <bits/stdc++.h>
using namespace std;

int arr2num(int a[3][3]){
    int x = 0;
    for(int i=0;i<3;++i)for(int j=0;j<3;++j){
        x = x * 3 +  a[i][j];
    }
    return x;
}
void num2arr(int num,int a[3][3]){
    for(int i=0;i<3;++i)for(int j=0;j<3;++j){
        a[i][j] = num % 3;
        num /= 3;
    }
}
char gc(){
    char c=getchar();
    for(;c!='.'&&c!='O'&&c!='X';c=getchar());
    return c;
}
int f[60010][2];
void dfs(int x,int turn){
    int c[3][3];
    if(f[x][turn]!=-1)return;
    num2arr(x,c);
    bool finished=1;
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)if(c[i][j]==0){finished=0;break;}
    if(finished){
    //    printarr(c);
        int contri = 0;
        for(int i=0;i<3;++i){
            if(c[i][0] == c[i][1] && c[i][0] == c[i][2]){
                if(c[i][0] == 2) ++ contri;
                else -- contri;
            }
            if(c[0][i] == c[1][i] && c[0][i] == c[2][i]) {
                if (c[0][i] == 2) ++contri;
                else --contri;
            }
        }
        if(c[0][0] == c[1][1] && c[0][0] == c[2][2]){
            if(c[0][0] == 2) ++ contri;
            else -- contri;
        }
        if(c[0][2] == c[1][1] && c[0][2] == c[2][0]){
            if(c[0][2] == 2) ++ contri;
            else -- contri;
        }
        f[x][turn] = contri;
    }
    else{
        int nowchess = turn + 1;
        for(int i=0;i<3;++i)for(int j=0;j<3;++j){
            if(c[i][j] == 0){
                c[i][j] = nowchess;
                int v = arr2num(c);
                dfs(v,turn^1);
                if(f[x][turn] == -1) f[x][turn] = f[v][turn^1];
                else{
                    if(turn == 0) f[x][turn] = min(f[x][turn],f[v][turn^1]);
                    else f[x][turn] = max(f[x][turn],f[v][turn^1]);
                }
                c[i][j] = 0;
            }
        }
    }
}
/*
 * 1 Bob    X  0
 * 2 Alice  O  1
 */
int main(){
    memset(f,-1,sizeof f);
    /*
    for(int i=0;i<59049;++i){
        dfs(i,0);
        dfs(i,1);
    }
     */
    int T; scanf("%d",&T);
    int t[3][3];
    while(T--){
        int turn; scanf("%d",&turn);
        for(int i=0;i<3;++i)for(int j=0;j<3;++j){
            char c=gc();
            if(c == '.')t[i][j]=0;
            else t[i][j]=(c=='O')+1;
        }
    //    printarr(t);
        dfs(arr2num(t),turn);
        printf("%d\n",f[arr2num(t)][turn]);
    }
    return 0;
}
