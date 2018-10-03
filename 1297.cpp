#include <bits/stdc++.h>
    using namespace std;
    double w , l;
    double area(double a){
        return (l-2*a)*(w-2*a)*a;
    }
    int main()
    {
       int test , cs = 1 ;
       scanf("%d",&test);
       while(test--){
          scanf("%lf%lf", &w , &l);
          double b = 0, e = 0.5*min(w,l);
          while(e-b > .000000001){
            double m1 = b +  (e-b)/3.0;
            double m2 = b + 2.0*(e-b)/3.0;
            if(area(m1) <= area(m2)+1e-7)
               b =m1;
            else e = m2;
          }
          double ans = area(b);
          printf("Case %d: %.15lf\n",cs++ , ans);
       }
     return 0;
    }
