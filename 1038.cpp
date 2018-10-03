#include <bits/stdc++.h>
using namespace std;
#define NN 100005
vector < int > divisor[NN];
double call(int n){
 
      if(n == 1) return 0;
      double divideBy =(double) divisor[n].size();
      double res = 1/divideBy;
      for(int i = 0 ; i< divideBy ;i++){
          int temp = divisor[n][i];
          if(temp != 1)
          res += (call(n/temp)+1)/divideBy;
      }
      double temp = 1.0-1/divideBy;
      res /= temp;
      return res;
}
int main()
{
    int test ,cs=1;
    scanf("%d",&test);
    for(int i = 1 ; i< NN ; i++){
         for(int j = i ; j< NN ; j+=i){
            divisor[j].push_back(i);
         }
    }
    while(test--){
         int n;
         scanf("%d",&n);
         double res = call(n);
         printf("Case %d: %.6lf\n",cs++ ,res);
    }
}
