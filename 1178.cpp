#include <bits/stdc++.h>
using namespace   std;
int main()
{
     double a , b , c, d;
     int test , cs = 1 ;
     scanf("%d",&test);
     while(test--){
         scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
         if(c < a) swap(a,c);
         double s = .5*(b+(c-a)+d);
         double area = sqrt(s*(s-b)*(s-(c-a))*(s-d));
         double h = (2*area)/(c-a);
         area += h*a;
         printf("Case %d: %.6lf\n",cs++ , area);
     }
 
     return 0;
}
