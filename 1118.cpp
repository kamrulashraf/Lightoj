clude <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define PI acos(-1)
#define pll pair < ll , ll >
ll squreDistance(pll a , pll b){
      ll x = a.ff-b.ff;
      ll y = a.ss-b.ss;
      return x*x+y*y;
}
 
double scetor(long long r , double angle){
      return r*r*.5*(angle-sin(angle));
}
int main()
{
      int test , cs = 1 ;
      scanf("%d",&test);
      while(test--){
          pll a, b;
          long long r , r1;
          scanf("%lld%lld%lld",&a.ff,&a.ss,&r);
          scanf("%lld%lld%lld",&b.ff,&b.ss,&r1);
          long long sqdis = squreDistance(a,b);
          double dis = sqrt((double) sqdis);
 
          // check tricky case
          if(r+r1 <= dis){
            double temp = 0;
            printf("Case %d: %.8lf\n",cs++ ,temp);
            continue;
          }
          else if(r+dis <= r1){
              double temp = PI*r*r;
              printf("Case %d: %.8lf\n",cs++ ,temp);
              continue;
 
          }
          else if(r1+dis <= r){
              double temp = PI*r1*r1;
              printf("Case %d: %.8lf\n",cs++ ,temp);
              continue;
          }
          double angle =2.0 * acos( (r*r+dis*dis - r1*r1)/(2.0*r*dis) );
          double res = scetor(r,angle);
          angle = 2.0*acos( (r1*r1+sqdis-r*r)/(2.0*r1*dis));
          res += scetor(r1,angle);
          printf("Case %d: %.8lf\n",cs++ ,res);
       }
}
