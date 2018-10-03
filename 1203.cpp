#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define NN 100000
#define pll pair < ll,ll >
#define PI                 acos(-1)
 
double grad(double n){ return (PI*n)/180; }
double agrad(double n){ return (180*n)/PI; }
 
// global variable
pll g;
 
ll disSq(pll a , pll b){
     ll x = a.ff - b.ff;
     ll y = a.ss - b.ss;
     ll ret = x*x+y*y;
     return ret;
}
 
ll triArea(pll a , pll b , pll c){
    // if anti clock wise positive else negative
    ll area  = a.ff*b.ss + b.ff*c.ss+c.ff*a.ss;
    area -= a.ss*b.ff+ b.ss*c.ff+c.ss*a.ff;
    return area;
}
 
bool convexComp(pll a, pll b){
    ll area = triArea(g,a,b);
    if(area > 0) return true;
    else if( area == 0 && disSq(g,a) < disSq(g,b))
       return true;
    return false;
}
pll inputPoint(){
    ll x , y;
    scanf("%lld%lld",&x,&y);
    return {x,y};
}
 
class ConvexHull{
    public:
      pll pointArr[NN], convex[NN];
      int n, m, cur; // m is convexhull no of point
    void convexSort(){
         g = pointArr[0];
         for(int i=1;i < n;i++){
             if(pointArr[i].ff < g.ff)
                g = pointArr[i];
             else if(pointArr[i].ff == g.ff && pointArr[i].ss < g.ss){
                g = pointArr[i];
             }
         }
         sort(pointArr,pointArr+n,convexComp);
    }
 
    void makeHull(){
         convexSort();
         if(n == 1){
             convex[0] = pointArr[0];
             convex[1] = pointArr[0];
             m = 1;
             return;
         }
 
         cur = 3;
         pointArr[n] = pointArr[0];
         convex[0] = pointArr[n-1];
         convex[1] = pointArr[0];
         convex[2] = pointArr[1];
         for(int i = 2; i<= n;i++){
             ll area = triArea(convex[cur-2],convex[cur-1],pointArr[i]);
             // cout << '#' << i << ' ' << cur << ' '  << convex[cur-2].ff << ' ' << convex[cur-2].ss << ' '<<  area << endl;
             if(area > 0){
                convex[cur] = pointArr[i];
                cur++;
             }
             else if(area == 0){
              // if take
              // convex[cur] = arr[i];
              // cur++;
              // if not take
              // else
              convex[cur-1] = pointArr[i];
            }
            else{
              cur--;
              i--;
            }
         }
 
         m = cur-1;
         convex[0] = convex[m-1];
    }
};
 
double findAgle(pll a , pll b , pll c){
    double B = disSq(a,c);
    double A = disSq(b,c);
    double C = disSq(a,b);
    // cout << A << ' ' << B << ' ' << C << endl;
    double angle = ((A+C-B)/(2*sqrt(A*C)));
    // cout << angle << endl;
    angle = acos(angle);
    return angle;
   
}
int main()
{
     int test , cs = 1;
     scanf("%d",&test);
     while(test--){
          int n;
          scanf("%d",&n);
          ConvexHull hull;
          hull.n =n;
          for(int i = 0 ; i< n ; i++){
              pll p = inputPoint();
              hull.pointArr[i].ff = p.ff;
              hull.pointArr[i].ss = p.ss;
          }
          hull.makeHull();
         
          double res  = 1e9;
          for(int i = 1 ; i< hull.m-1 ; i++){
              double angle= findAgle(hull.convex[i-1],hull.convex[i],hull.convex[i+1]);
              angle = agrad(angle);
              res = min(angle,res);
          }
          int ss = hull.m-1;
          double angle = findAgle(hull.convex[ss-1],hull.convex[ss],hull.convex[1]);
          angle = agrad(angle);
          res = min(res,angle);
          if(hull.m-1 <= 2) res = 0;
          printf("Case %d: %.6lf\n",cs++ , res);
          // for(int i = 0 ; i<= ss ; i++){
          //     cout << hull.convex[i].ff << ' ' << hull.convex[i].ss << endl;
          // }
 
     }
     return 0;
}
