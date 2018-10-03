#include <bits/stdc++.h>
using namespace std;
int mod = 100000007;
int dp[3][15001];
int fun(int n){
    if(n > 0) return n;
    return 0;
}
void precal(int s, int n, int k){
    // pre calculate
    for(int i=1;i<=k;i++) dp[1][i] = dp[1][i-1]+1;
    for(int i = k+1 ; i<= s ; i++)  dp[1][i] = dp[1][i-1];
    int flag = 1;
    for(int i = 2 ; i<= n;i++){
        flag = 1 - flag;
        for(int j=1;j<=s;j++){
            dp[flag][j] = (dp[1-flag][j-1]+dp[flag][j-1]-dp[1-flag][fun(j-k-1)])%mod;
        }
    }
 
//  for(int i = 0 ; i<= 1 ; i++){
//     for(int j = 0 ; j<= s ; j++){
//          cout << dp[i][j] << ' ' ;
//       } cout << endl;
//  }
return;
}
int main()
{
    int test ,cs =1;
 
    scanf("%d",&test);
    while(test--){
        int n , k , s;
        scanf("%d%d%d",&n,&k,&s);
        memset(dp,0,sizeof dp);
        precal(s,n,k);
        int res = dp[n&1][s]-dp[n&1][s-1];
        res = (res+mod)%mod;
        printf("Case %d: %d\n",cs++,res);
 
    }
    return 0;
}
 
