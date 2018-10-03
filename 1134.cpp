#include <bits/stdc++.h>
using namespace std;
#define N  100005
 
long long dp[N];
int a[N];
int main()
{
     // freopen("in.txt","r",stdin);
     int test , cs = 1, n, d;
     scanf("%d",&test);
     while(test--){
         memset(dp,0,sizeof dp);
         scanf("%d%d",&n,&d);
         for(int i = 1 ; i<= n ; i++){
              scanf("%d",&a[i]);
         }
         for(int i = 1 ; i<= n ; i++){
             a[i] = (a[i-1]+a[i])%d;
         }
 
   
 
         dp[0] = 1;
         long long res =0;
         for(int i = 1 ; i<= n ; i++){
              res += dp[a[i]];
              dp[a[i]]++;
 
         }
         printf("Case %d: %lld\n",cs++ , res);
     }
 
}
