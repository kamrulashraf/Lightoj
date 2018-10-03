#include <bits/stdc++.h>
using namespace std;
#define PI                   2.0*acos(0.0)   // acos(-1)
 
#define ff first
#define ss second
#define pii pair < double,double>
double grad(double n){ return (PI*n)/180; }
double agrad(double n){ return (180*n)/PI; }
 
double disSq(pii a, pii b){
    double x = a.ff-b.ff;
    double y = a.ss-b.ss;
    return x*x+y*y;
}
int main()
{
     pii c , a , b;
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
          scanf("%lf %lf %lf %lf %lf %lf",&c.ff,&c.ss,&a.ff , &a.ss,&b.ff,&b.ss);
          double r = disSq(c,a);
          double cc = disSq(a,b);
          double temp = (r+r-cc)/ (2*r);
          double angle = acos(temp);
          double res =  angle*sqrt(r) ;
          printf("Case %d: %.6lf\n",cs++ ,res);
 
     }
 
     return 0;
}
