#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define inf 1e9
int  n , a[N] , k;
int dp[N];
 
int call(int indx){
     if(indx == n) return 0;
     else if(indx > n) return inf;
     int key = a[indx]+2*k;
     int pos = upper_bound(a,a+n,key)-a;
//     cout << indx << ' ' << pos << endl;
     if(dp[indx] != -1) return dp[indx];
     int temp = pos-indx;
     int mmin = inf;
     if(temp >= 3) mmin = min(mmin,1+call(pos));
     if(temp >= 4) mmin = min(mmin,1+call(pos-1));
     if(temp >= 5) mmin = min(mmin,1+call(pos-2));
     return dp[indx] = mmin;
 
}
int main()
{
   // freopen("in.txt","r",stdin);
   int test , cs = 1 ;
   scanf("%d",&test);
   while(test--){
       scanf("%d%d",&n,&k);
       for(int i = 0 ; i < n ; i++){
            scanf("%d",&a[i]);
       }
       a[n] = inf;
       sort(a,a+n);
       
       memset(dp,-1,sizeof dp);
       int res = call(0);
       if(res == inf) res = -1;
       printf("Case %d: %d\n",cs++ , res);
   }
}
