#include <bits/stdc++.h>
using namespace std;
#define N 50005
#define READ freopen("input.txt","r",stdin);
#define ll long long
ll b[N], dp1[N], dp2[N];
char s[N] , sub[N], temp[N];
 
 
int call(int n, ll dp[]){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = 1+call(b[n],dp);
}
 
 
void kmpPreprocess(char sub[]){
    int j=-1, i=0;
    b[i] = j;
    int sz = strlen(sub);
    for(i=0;i<sz;){
       while(j>=0 && sub[i]!=sub[j])
          j = b[j];
 
       i++;
       j++;
       b[i] = j;
    }
}
 
 
 
void kmp(char s[] , char sub[], ll save[]){
    ll dp[N];
    int n = strlen(s);
    int m = strlen(sub);
    memset(dp,-1,sizeof dp);
    kmpPreprocess(sub);
    int j = 0 , i = 0;
    for(i=0;i<n;){
        while(j>=0 && s[i] != sub[j])
            j = b[j];
        j++;
        save[i] = call(j,dp);
        // if(j==m) save[i]--;
        // cout << i << ' ' << j << ' '  << save[i] << endl;
        // cout << b[3] << endl;
        i++;
       
    }
}
 
 
int main()
{
   // READ;
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
      memset(dp1,0,sizeof dp1);
      memset(dp2,0,sizeof dp2);
      getchar();
      scanf("%s",s);
      scanf("%s",sub);
 
      int ssz = strlen(s);
      int subsz = strlen(sub);
      strcpy(temp,sub);
      temp[subsz-1] = '\0';
      kmp(s,temp,dp1); // pass temp for proper prefix
 
      reverse(s,s+ssz);
      reverse(sub,sub+subsz);
 
      strcpy(temp,sub);
      temp[subsz-1] = '\0';
      kmp(s,temp,dp2);  // pass temp for proper prefix
 
      // for(int i = 0 ; i< ssz ; i++){
      //    cout << dp1[i] << ' ' << dp2[i] << endl;
      // }
      // cout << endl;
      long long res = 0;
      for(int i = 0 ; i< ssz ; i++){
         res += dp1[i]*dp2[ssz-i-2];
         // cout << i << ' ' << dp1[i] << ' ' << dp2[ssz-i-2] << endl;
      }
 
      printf("Case %d: %lld\n",cs++ ,res);
 
   }
 
   return 0;
}
