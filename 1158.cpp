#include <bits/stdc++.h>
using namespace std;
string s; int d;
long long n;
int allTaken;
int dp[1025][1002];
int mark[10];
int fac[12];
//#################
 
void factor(){
    fac[0] = 1;
    for(int i = 1 ; i<= 10 ; i++){
         fac[i] = fac[i-1]*i;
    }
}
 
long long call(int mask,int sum){
    long long res =0;
//    cout << mask << ' ' << sum << endl;
    if(mask == allTaken){
        if(sum%d==0){
            return 1;
        }
        else return 0;
    }
    if(dp[mask][sum] != -1) return dp[mask][sum];
    for(int i = 0 ; i< s.size() ; i++){
         if( (mask& (1<< i)) == 0){
            int temp = mask;
            temp |= (1 << i);
            res += call(temp,(sum*10+s[i]-48)%d);
         }
    }
    return dp[mask][sum] = res;
}
int main()
{
     int test , cs=1;
     scanf("%d",&test);
     factor();
     while(test--){
         allTaken = 0;
         memset(dp,-1,sizeof dp);
         cin >> s;
         scanf("%d",&d);
         for(int i = 0 ; i< s.size() ; i++){
             allTaken |= (1<<i);
         }
         long long res = call(0,0);
         for(int i=0;i<s.size();i++) mark[s[i]-48]++;
         for(int i = 0 ; i<10 ; i++){
             int temp = max(mark[i],1);
             res /= fac[temp];
         }
         printf("Case %d: %lld\n",cs++,res);
         memset(mark,0,sizeof mark);
     }
     return 0;
}
