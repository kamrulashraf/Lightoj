#include <bits/stdc++.h>
#define PI                   2.0*acos(0.0)   // acos(-1)
 
using namespace std;
int main()
{
     int test , cs = 1 ;
     scanf("%d",&test);
     while(test--){
         double r1 , r2 , r3;
         scanf("%lf%lf%lf",&r1,&r2,&r3);
         double a, b, c; // triangle side len
         a = r1+r2;
         b = r2+r3;
         c = r3 + r1;
         double s = (a+b+c)/2.0;
         // find triangle area
         double area = sqrt(s*(s-a)*(s-b)*(s-c));
         // subtract 3 segment area
         double anglea , angleb , anglec;
         double segment1 , segment2 , segment3;
         double temp = (a*a+b*b-c*c)/2*a*b;
         angleb =  acos((a*a+b*b-c*c)/(2*a*b));
         anglea = acos((a*a+c*c-b*b)/(2*a*c));
         anglec = acos((b*b+c*c-a*a)/(2*b*c));
         segment1 = r1*r1*anglea*.5;
         segment2 = r2*r2*angleb*.5;
         segment3 = r3*r3*anglec*.5;
         area -= (segment1+segment2+segment3);
         printf("Case %d: %.6lf\n",cs++ , area);
     }
 
     return 0;
}
