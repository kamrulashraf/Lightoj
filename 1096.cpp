#include <bits/stdc++.h>
using namespace std;
#define MOD 10007
#define rep(i,x,y) for(int i=x;i<y;i++)
#define ll long long
int a , b , c , n;
void multiply(int a[4][4],int b[4][4]){
    int sum[4][4] = {0};
    rep(i,0,4) rep(j,0,4) rep(k,0,4)
       sum[i][j] = (sum[i][j]+ (a[i][k]*b[k][j])%MOD)%MOD;
    rep(i,0,4) rep(j,0,4) a[i][j] = sum[i][j];
}
void power(int matrix[4][4] , int n){
     if(n == 0 || n == 1) return;
     int A[4][4]={ {a,0,b,1} , {1,0,0,0} , {0,1,0,0} ,{0,0,0,1} };
     power(matrix,n/2);
     multiply(matrix,matrix);
     if(n&1) multiply(matrix,A);
}
int main()
{
    int test , cs= 1 ;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d%d%d",&n,&a,&b,&c);
        int matrix[4][4]={ {a,0,b,1} , {1,0,0,0} , {0,1,0,0} ,{0,0,0,1} };
        power(matrix , n-2);
        ll res = 0;
        res = (matrix[0][3]*c)%MOD;
        if(n <= 2) res = 0;
        printf("Case %d: %lld\n",cs++ , res);
 
    }
}
 
