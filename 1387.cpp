#include <bits/stdc++.h>
using namespace std;
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   while(test--){
       int n;
       cin >> n;
       int res  = 0;
       printf("Case %d:\n",cs++);
       while(n--){
               string a ;
               int b;
               cin >> a;
               if(a == "donate"){
                  cin >> b;
                  res += b;
               }
               else{
                  cout << res << endl;
               }
       }
   }
   return 0;    
}
