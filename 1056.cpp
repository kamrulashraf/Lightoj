#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
double fun(double l, double a , double b){
     double w = (b/a)*l;
     double ta = l/2;
     double tb = w/2;
     double rr = (ta*ta+tb*tb);
     double angle = acos((rr+rr-w*w)/(2*rr));
     double perimeter =  sqrt(rr)*angle;
     return (2*perimeter+2*l);
}
int main()
{
    int test , cs=  1;
    scanf("%d",&test);
    while(test--){
        double a , bb;
        scanf("%lf : %lf",&a,&bb);
        double b = 0 , e = 500;
        while(e - b > EPS){
            double m = (b+e)/2.0;
            if(fun(m,a,bb) < 400){
                b= m;
            }
            else e = m;
        }
        double resl = (b+e)/2;
        double resw = (bb/a)*resl;
        printf("Case %d: %.6lf %.6lf\n",cs++ ,resl,resw);
    }
   return 0;
}
 
