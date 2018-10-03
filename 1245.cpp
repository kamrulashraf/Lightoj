#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long num;
   int test , cs = 1;
   scanf("%d", &test);
   while(test--){
      scanf("%lld", &num);
      long long sum = 0;
      long long temp = sqrt(num);
      for(int i = 1 ; i <= temp ; i++){
      //   cout << i << endl;
         sum += num/i;
         if(num/i != i)
         sum += i*(num/i - num/(i+1));
      }
      printf("Case %d: %lld\n", cs++ , sum);
   }
  return 0;
}
 
