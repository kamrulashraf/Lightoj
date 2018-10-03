#include <bits/stdc++.h>
using namespace std;
int n , make;
long long dp[26][151];
long long call(int i , int sum){
    if(i >= n){
       if(sum >= make){
         return 1;
       }
       return 0;
    }
    long long res = 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    for(int j = 1 ; j<= 6 ; j++){
        res += call(i+1,sum+j);
    }
    return dp[i][sum] = res;
}
 
long long call1(int i , int sum){
    if(i >= n){
           return 1;
    }
    long long res = 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    for(int j = 1 ; j<= 6 ; j++){
        res += call1(i+1,sum+j);
    }
    return dp[i][sum] = res;
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
       scanf("%d%d",&n,&make);
       memset(dp,-1,sizeof dp);
       long long res = call(0,0);
       memset(dp,-1,sizeof dp);
       long long res1 = call1(0,0);
       long long g = __gcd(res,res1);
       res = res/g;
       res1 = res1/g;
       if(res && res1 != 1)
        printf("Case %d: %lld/%lld\n",cs++ , res, res1);
       else printf("Case %d: %lld\n",cs++, res);
 
    }
    return 0;
}
