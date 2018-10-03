#include <bits/stdc++.h>
using namespace std;
#define N          2*100005
#define ll         long long
#define  ull       unsigned long long
#define inf        (ll)  1e9
#define grey       1
#define black      2
#define white      0
#define  rep(i,x,y)   for(int i = x ; i< y ; i++)
vector <int > prime;
template < class T > inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T > inline T lcm(T a, T b) {return a/gcd(a,b) * b;}
/*********************************************/
 
 
#define ashraf
#ifdef ashraf
     #define so(args...) {cerr<<"so: "; dbg,args; cerr<<endl;}
#else
    #define so(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
ll a[N] ,save[N], save1[N], mmax[N] , mmax1[N];
void lis(int n){
    ll sub[N], len = 0;
    rep(i,0,n+1) sub[i] = inf;
    sub[0] = -inf;
    for(int i = 0 ; i< n ; i++){
       ll pos = lower_bound(sub,sub+len+1 , a[i]) - sub;
       sub[pos] = a[i];
       len = max(len , pos);
       save[i] = len;
       mmax[i] = sub[len];
    }
 
}
 
void revLis(int n){
    ll sub[N], len = 0;
    rep(i,0,n+1) sub[i] = inf;
    sub[0] = -inf;
    for(int i = n-1 ; i >= 0 ; i--){
       ll pos = lower_bound(sub,sub+n , a[i]) - sub;
       sub[pos] = a[i];
       len = max(len , pos);
       save1[i] = len;
       mmax1[i] = sub[len];
    }
 
}
int main()
{
  // freopen("a.txt","w",stdout);
   int test , cs = 1;
   scanf("%d",&test);
 
   while(test--){
      int n;
      scanf("%d",&n);
      rep(i,0,n) scanf("%lld",&a[i]);
      lis(n);
      revLis(n);
      ll ans = 0;
      for(int i = 0 ; i < n-1  ; i++){
           if(mmax[i] > mmax1[i+1] && save[i] > save1[i+1]){
              int temp = 2*save1[i+1]+1;
              if(temp&1)
              ans = max(ans, 2*save1[i+1]+1);
           }
      }
      if(!ans) ans++;
      printf("Case %d: %lld\n",cs++ , ans);
   }
 
}
