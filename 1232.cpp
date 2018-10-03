#include <bits/stdc++.h>
using namespace std;
#define NN 105
int n , make;
int mod = 100000007;
int a[NN];
int dp[10005];
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&n,&make);
        for(int i = 0 ; i< n ; i++)
             scanf("%d",&a[i]);
        memset(dp,0,sizeof dp);
        dp[0]=1;
       
        for(int i  = 0 ; i< n ; i++){
            for(int j = a[i] ; j<= make ; j++){
                dp[j] += dp[j-a[i]];
                if(dp[j] > mod) dp[j] %= mod;
            }
        }
        printf("Case %d: %d\n",cs++,dp[make]);
    }
}
