#include <bits/stdc++.h>
using namespace std;
#define NN 2001
#define pii pair < int , int >
#define ff first
#define ss second
#define inf 1e9
 
int r , c;
int dp[NN][NN];
string a[NN];
int b[NN];
long long histogram(int indx){
     long long memo[NN], b[NN];
     memset(memo,0,sizeof memo);
     stack < pii > st;
     st.push({-inf,-1});
     for(int i=0;i<c;i++) b[i] = dp[indx][i];
     for(int i=0;i<c;i++){
          while(st.top().ff >= b[i])
             st.pop();
          memo[i] += i-st.top().ss;
          st.push({b[i],i});
     }
     while(!st.empty()) st.pop();
     st.push({-inf,-1});
     reverse(b,b+c);
 
     for(int i=0;i<c;i++){
        while(st.top().ff >= b[i])
            st.pop();
        memo[c-i-1] += i-st.top().ss-1;
        st.push({b[i],i});
     }
     reverse(b,b+c);
     long long ans = 0;
     for(int i=0;i<c;i++)
        ans = max(ans,memo[i]*b[i]);
 
     return ans;
 
}
 
void clr(){
     memset(dp,0,sizeof dp);
}
int main()
{
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
        clr();
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++)
                cin >> a[i];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                 if(i==0){
                    if(a[i][j]=='0')
                        dp[i][j] = 1;
                 }
                 else{
                     if(a[i][j]=='0')
                        dp[i][j] = dp[i-1][j]+1;
                     else dp[i][j] = 0;
                 }
            }
        }
        long long res = 0;
        for(int i = 0 ; i< r ; i++){
            res = max(res,histogram(i));
        }
        printf("Case %d: %lld\n",cs++,res);
     }
}
