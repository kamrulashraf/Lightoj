#include <bits/stdc++.h>
using namespace std;
#define NN 100000
#define inf 1e9
int a[NN];
 
bool fun(int m, int n){
   bool flag = 0;
   for(int i = 1 ; i<= n ; i++){
      if(a[i] - a[i-1] < m){
        continue;
      }
      if(a[i] - a[i-1] == m){
        m--;
        continue;
      }
      flag = 1;
      break;
   }
   return (1-flag);
}
int call(int n){
     int b = 0 ; int e = inf;
     while(b <= e){
          int m = (b+e)/2.0;
          if(fun(m,n)){
            e = m-1;
          }
          else b = m+1;
     }
     return b;
}
int main()
{
     int test , cs = 1;
     cin >> test ;
     while(test--){
         int n;
         scanf("%d",&n);
         for(int i = 1 ; i<= n ; i++){
            scanf("%d",&a[i]);
         }
         int res = call(n);
         printf("Case %d: %d\n",cs++ ,res);
     }
   return 0;
}

