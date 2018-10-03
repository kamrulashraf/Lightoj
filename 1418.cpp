#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair < ll , ll >
#define ff first
#define ss second
#define NN 100005
// pick's theorm ** p(area) = (b)/2 + i -1;
pll inputPoint(){
    ll a ,b;
    scanf("%lld %lld",&a,&b);
    return {a,b} ;
}
 
template < class T> inline T gcd(T a, T b) {
  while (a > 0 && b > 0)
    a > b ? a%=b : b%=a;
  return a + b;
}
 
int pointInSegment(pll a ,pll b){
     pll temp;
     temp.ff = abs(b.ff-a.ff);
     temp.ss = abs(b.ss-a.ss);
     int g = gcd(temp.ff,temp.ss);
     return abs(g)-1;
}
pll point[NN];
int main()
{
    int test ,cs = 1;
    scanf("%d",&test);
    while(test--){
        ll n;
        scanf("%lld",&n);
        for(int i = 0 ; i< n ; i++){
             point[i] = inputPoint();
        }
 
        ll area = 0;
        for(int i = 0 ; i< n ; i++){
            area += point[i%n].ff*point[(i+1)%n].ss;
        }
        for(int i = 0 ; i< n ; i++){
            area -= point[i%n].ss*point[(i+1)%n].ff;
        }
        area = abs(area);
        ll save = n;
        for(int i = 0 ; i<n ; i++){
            save += pointInSegment(point[i],point[(i+1)%n]);
        }
        ll ret =  (area - save + 2)/2;
        printf("Case %d: %lld\n",cs++ ,ret);
 
    }
 
    return 0;
}
