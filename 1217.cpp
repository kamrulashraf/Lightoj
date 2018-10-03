#include <bits/stdc++.h>
using namespace std;
#define NN 1005
int a[NN], n;
int dp[NN][2];
int call(int i, int flag){
    if(dp[i][flag] != -1) return dp[i][flag];
    if(i>= n-flag) return 0;
    int ret1 = 0, ret2 = 0;
    ret1 = a[i]+call(i+2,flag);
    ret2 = call(i+1,flag);
    return dp[i][flag] = max(ret1,ret2);
}
int main()
{
    int test ,cs = 1;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof dp);
        int res = call(0,1);
        res = max(res,call(1,0));
        printf("Case %d: %d\n",cs++,res);
    }
   return 0;
}
