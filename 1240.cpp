#include <bits/stdc++.h>
using namespace std;
#define EPS   1e-12
struct point
{
    double a , b ,c;
    point(double x, double y , double z){
      a = x, b = y, c = z;
    }
};
point x(0,0,0) , y(0,0,0) , z(0,0,0), ss(0,0,0);
 
double fun(double m){
    point temp(x.a+m*ss.a , x.b+m*ss.b , x.c+m*ss.c);
    double aa = temp.a-z.a;
    double bb = temp.b-z.b;
    double cc = temp.c-z.c;
    return (double) (aa*aa+bb*bb+cc*cc);
}
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        scanf("%lf%lf%lf",&x.a,&x.b,&x.c);
        scanf("%lf%lf%lf",&y.a,&y.b,&y.c);
        scanf("%lf%lf%lf",&z.a,&z.b,&z.c);
        ss.a = y.a-x.a;
        ss.b = y.b-x.b;
        ss.c = y.c-x.c;
 
        double b = 0 , e = 1;
        while(e- b > EPS){
            double m1 = b + (e-b)/3.0;
            double m2 = b + (2*(e-b))/3.0;
            if(fun(m1) < fun(m2)){
               e = m2;
            }
            else b = m1;
        }
        double res = fun(b);
        res = sqrt(res);
        printf("Case %d: %.8lf\n",cs++, res);
    }
    return 0;
}
