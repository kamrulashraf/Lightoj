// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define white                0
#define grey                 1
#define black                2
#define ll                   long long
#define ull                  unsigned long long
#define PI                   2.0*acos(0.0)   // acos(-1)
#define pi                   pair <int,int>
#define rep(i,x,y)           for(int i = x ; i < y ; i++)
#define fst(x)               v[x].first
#define sd(x)                v[x].second
#define X(i)                 x+fx[i]
#define Y(i)                 y+fy[i]
#define BOUNDRY(i,j)         ((i>=0 && i < r) && (j>= 0 && j< c))
#define WRITE                freopen("a.txt","w",stdout);
//***********************************************
 
#define ashra
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
 
 
//******************************************************
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
 ll a[1000005];
int main()
{
//  WRITE;
  int test , cs = 1;
  cin >> test;
  while(test--){
      long long n , que;
      scanf("%lld %lld", &n, &que);
      rep(i,1,n+1) scanf("%lld", &a[i]);
      long long posSum = 0, negSum = 0;
      long long over = 0;
      for(int i = 1, j = n ; i<= n ; i++, j--){
           long long an = (n-i)*a[i];
           long long bn = (n-i)*a[j];
           over += an;
           over -= bn;
          // so(i ,a[i], a[j], n);
      }
      printf("Case %d:\n",cs++);
      for(int i = 0 ; i< que ; i++){
         int temp;
         scanf("%d",&temp);
         if(temp == 1){
            long long ans = over;
            printf("%lld\n", ans);
         }
         else{
            int pos , val;
            scanf("%d%d",&pos,&val);
            pos++;
            long long an = (n-pos)*a[pos];
            long long bn = (pos-1)*a[pos];
            over -= an;
            over += bn;
            a[pos] = val;
            an = (n-pos)*a[pos];
            bn = (pos-1)*a[pos];
            over += an;
            over -= bn;
           // so(posSum , negSum);
         }
      }
  }
}
