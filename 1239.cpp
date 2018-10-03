#include <bits/stdc++.h>
using namespace  std;
 
#define N 100005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PI acos(-1.0)
 
double grad(double n){ return (PI*n)/180; }
double agrad(double n){ return (180*n)/PI; }
 
#define pll pair < ll  , ll>
 
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
    scanf("%lld %lld",&x,&y);
    return MP(x,y);
}
 
class ConvexHull{
    public:
      pll pointArr[N], convex[N];
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
         pll &temp = pointArr[n];
         temp = pointArr[0];
         for(int i = 0 ; i< 2 ; i++){
            convex[i+1] = pointArr[i];
         }
 
         for(int i = 2; i <= n;i++){
             ll area = triArea(convex[cur-2],convex[cur-1],pointArr[i]);
             if(area > 0){
                convex[cur] = pointArr[i];
                cur++;
             }
             else if(area == 0){
              // if take
              convex[cur] = pointArr[i];
              cur++;
              // if not take
              //  convex[cur-1] = pointArr[i];
            }
            else{
              cur--;
              i--;
            }
         }
         m = cur-1;
         convex[0] = convex[m-1];
         convex[m] = convex[1];
    }
};
 
 
 
int main()
{
    // freopen("in.txt" , "r" , stdin);
    int test, cs = 1;
    sca(test);
    while(test--){
        int n ;
        double r;
        scanf("%d%lf",&n,&r);
 
        ConvexHull var;
        var.n = n;
 
        for(int i = 0 ; i< n ; i++){
            var.pointArr[i] = inputPoint();
        }
 
        var.makeHull();
 
 
 
        double res = 0;
        for(int i =1 ; i< var.m ; i++){
            res += sqrt(disSq(var.convex[i] , var.convex[i+1]));
            pll &temp = var.convex[i];
        }
 
 
        res += 2*PI*r;
 
        printf("Case %d: %.10lf\n",cs++ , res);
    }
}
