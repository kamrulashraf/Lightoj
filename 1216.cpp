#include <bits/stdc++.h>
#define PI                   2.0*acos(0.0)   // acos(-1)
 
using namespace std;
int main()
{
     int test , cs = 1 ;
     scanf("%d",&test);
     while(test--){
        double r1 , r2 , h , p;
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        double x = (h*r2)/(r1-r2);
        double r3 = (r2*(p+x)) / x;
        double volume = (PI*p*(r2*r2+r2*r3+r3*r3)) / 3.0;
        printf("Case %d: %.6lf\n",cs++,volume);
     }
 
     return 0;
}
