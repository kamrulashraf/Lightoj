// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define MOD   1000000007
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
long long fac[1001], dp[1001][1001];
void factorial(){
  fac[0] = 1;
  for(int i = 1 ; i<= 1000 ; i++){
     fac[i] = (fac[i-1]*i)%MOD;
  }
}
long long ncr(long long n , long long r){
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = (ncr(n-1, r) + ncr(n-1 , r- 1))%MOD;
}
 
long long solve(long long a , long long b){
  ll res = fac[a];
  for(int i = 1 ; i<= b ; i++){
     long long temp = (ncr(b,i)*fac[a-i])%MOD;
     if(i&1) res -= temp;
     else res += temp;
     res = (res+MOD)%MOD;
  }
  return res;
}
int main()
{
   memset(dp,-1,sizeof(dp));
   factorial();
   int test , cs = 1;
   scanf("%d", &test);
   while(test--){
      long long n , m , k;
      scanf("%lld %lld %lld", &n , &m , &k);
      long long ans = (ncr(m,k)*solve(n-k,m-k))%MOD;
      printf("Case %d: %lld\n",cs++ ,ans);
   }
}
