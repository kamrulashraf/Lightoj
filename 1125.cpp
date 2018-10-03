#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n , m , d, q,arr[201];
ll dp[201][21][11];
ll call(int i , ll sum , int remain){
    if(remain <0) return 0;
    if(i >= n){
        if(remain == 0 && sum%d == 0){
            return 1;
        }
        else return 0;
    }
    if(dp[i][sum][remain] != -1) return dp[i][sum][remain];
    ll ret = sum+arr[i];
    ret %= d;
    if(ret < 0) ret += d;
    ll p1 = call(i+1,ret,remain-1);
    ll p2 = call(i+1,sum,remain);
    return dp[i][sum][remain] = p1+p2;
}
int main()
{
     int test ,cs = 1;
     scanf("%d",&test);
     while(test--){
         printf("Case %d:\n",cs++);
         scanf("%d%d",&n,&q);
         for(int i = 0 ; i< n ; i++){
             scanf("%d",&arr[i]);
         }
         for(int i = 0 ; i< q ; i++){
             scanf("%d%d",&d,&m);
             memset(dp,-1,sizeof dp);
             long long res = call(0,0,m);
             printf("%lld\n",res);
         }
     }
}
