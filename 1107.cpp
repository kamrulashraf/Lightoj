// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define inf                  1e7
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
#define MOD
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
void take(int &x){ scanf("%d", &x);}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int n , k;
int main()
{
 //  WRITE;
   int test , cs  = 1;
   take(test);
   while(test--){
        printf("Case %d:\n",cs++);
       int a[5];
       rep(i,0,4) take(a[i]);
      // rep(i,0,4) cout << a[i] << ' ';
       int n;
       take(n);
       rep(i,0,n){
         int x , y;
         take(x);take(y);
         if(x >= min(a[0],a[2]) && x <= max(a[0],a[2]) && y >= min(a[1],a[3]) && y <= max(a[1],a[3])){
            puts("Yes");
         }
         else puts("No");
       }
   }
}
