#include <bits/stdc++.h>
using namespace std;
double dp[505][505][2];
bool vis[505][505][2];
double call(int a , int b, int i){
     if(a+b == 1){
        if(b) return dp[a][b][i] = 1;
        return dp[a][b][i] = 0;
     }
     double res = 0, red = a , blue = b;
     if(vis[a][b][i]) return dp[a][b][i];
     if(i == 1){
          if(a>0) res += (red*call(a-1,b,1-i))/(red+blue);
          if(b>0) res += (blue*call(a,b-1,1-i))/(red+blue);
     }
     else{
        if(b>0) res += call(a,b-1,1-i);
     }
     vis[a][b][i&1] = true;
     return dp[a][b][i&1] = res;
 
}
int main()
{
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        int a  , b;
        scanf("%d%d",&a,&b);
        double res = call(a, b,1);
        printf("Case %d: %.8lf\n",cs++ ,res);
     }
 
     return 0;
}
 
