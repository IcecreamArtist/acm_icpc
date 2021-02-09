#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 110;
const double eps = 1e-8;
int out[N];  // 用来算概率
vector<int> pre[N];  // 前驱

typedef double Matrix[N][N];

Matrix matrix;

void gauss_jordan(Matrix A,int n){
    int i,j,k,r;
    for(i=0;i<n;++i){
        r=i;
        for(j=i+1;j<n;++j)
            if(fabs(A[j][i])>fabs(A[r][i])) r=j;
        if(fabs(A[r][i])<eps) continue;//i是自由变量
        if(r!=i) for(j=0;j<=n;++j) swap(A[i][j],A[r][j]);
        // 变成对角矩阵
        for(k=0;k<n;++k) if(k!=i)
            for(j=n;j>=i;--j)
                A[k][j]-=A[k][i]/A[i][i]*A[i][j];
    }
}

int inf[N];  // check if is inf
int main(){
    int cas=0;
    while(~scanf("%d",&n),n){
        int u,v;
        for(int i=0;i<n;++i) pre[i].clear();
        memset(out,0,sizeof(out));
        while(~scanf("%d%d",&u,&v),(u||v)){
            u--,v--;
            pre[v].push_back(u);
            out[u]++;
        }
        memset(matrix,0,sizeof(matrix));
        for(int i=0;i<n;++i){
            matrix[i][i]=1;
            for(int j=0;j<pre[i].size();++j)
                matrix[i][pre[i][j]]-=1.0/out[pre[i][j]];
            if(i==0) matrix[i][n]=1;
        }
        gauss_jordan(matrix,n);
        memset(inf,0,sizeof(inf));
        for(int i=n-1;i>=0;--i){
            if(fabs(matrix[i][i])<eps&&fabs(matrix[i][n])>eps) inf[i]=1;
            for(int j=i+1;j<n;++j)
                if(fabs(matrix[i][j])>eps&&inf[j]) inf[i]=1;
        }
        int q;scanf("%d",&q);
        cout<<"Case #"<<++cas<<":"<<endl;
        while(q--){
            scanf("%d",&u);u--;
            if(inf[u]) cout<<"infinity"<<endl;
            else printf("%.3lf\n",fabs(matrix[u][u])<eps?0.0:matrix[u][n]/matrix[u][u]);
        }
    }
}