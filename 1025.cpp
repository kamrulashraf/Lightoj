#include <bits/stdc++.h>
using namespace  std;
#define NN 65
long long dp[NN][NN];
string s;
long long call(int i , int j){
    if(i == j) return 1;
    if(i > j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i] == s[j])
        return dp[i][j] = 1 + call(i+1,j) + call(i,j-1);
    else return dp[i][j] = call(i+1,j)+call(i,j-1)-call(i+1,j-1);
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0);
 
    int test , cs = 1;
    cin >> test;
    while(test--){
        cin >> s;
        int len = s.size();
        memset(dp,-1,sizeof dp);
        long long res = call(0,len-1);
        printf("Case %d: %lld\n",cs++ , res);
    }
}
