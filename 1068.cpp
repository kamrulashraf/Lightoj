#include <bits/stdc++.h>
using namespace std;
int a , b, k;
string sa , sb;
int dp[10][2][2][92][92];
string convertStringTo(int a){
    string temp;
    for(int i = 0 ; i< 10 ; i++){
         temp +=(char) ((a%10)+48);
         a/=10;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
 
int call(int i,bool islow , bool ishigh,int sum, int num){
 
    if(i >=  10 ){
        if(sum%k == 0 && num%k==0) return 1;
        else return 0;
    }
    if(dp[i][islow][ishigh][sum][num] != -1) return dp[i][islow][ishigh][sum][num];
    int res =  0;
    int up = sb[i]-48;
    int lw = sa[i]-48;
    for(int j = 0 ; j<= 9 ; j++){
         int temp = sum+j;
         if(islow && j < lw) continue;
         if(ishigh && j > up) continue;
         res += call(i+1,islow&(j==lw),ishigh&(j==up),sum+j,(num*10+j)%k);
    }
    return dp[i][islow][ishigh][sum][num] = res;
}
int main()
{
    int test , cs =1;
    scanf("%d",&test);
    while(test--){
         int res;
         scanf("%d%d%d",&a,&b, &k);
         sa = convertStringTo(a);
         sb = convertStringTo(b);
         memset(dp,-1,sizeof dp);
         if(k>91) res = 0;
         else
           res = call(0,1,1,0,0);
         printf("Case %d: %d\n",cs++,res);
    }
    return 0;
}
