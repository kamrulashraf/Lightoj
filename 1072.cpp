// sin(angle) = r/ (R-r)
// by dirving from here we get formulas
 
#include <bits/stdc++.h>
using namespace   std;
#define PI                   2.0*acos(0.0)   // acos(-1)
 
int main(){
    int test , cs = 1;
    double R ;
    int n;
    scanf("%d",&test);
    while(test--){
       scanf("%lf%d",&R,&n);
       double ss = sin(PI/n);
       double res = (ss*R)/(ss+1);
       printf("Case %d: %.6lf\n",cs++ ,res);
    }
 
  return 0;
}
