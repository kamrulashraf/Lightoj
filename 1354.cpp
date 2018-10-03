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
int con(int a){
   int ans = 0,temp = 10;
   int i   = 0;
   while(a && i <= 9){
     if(!i) ans = a%2;
     else{
       ans =  (a%2)*temp + ans;;
       temp = temp*10;
     }
     a/=2;
     i++;
   }
  // so(ans);
   return ans;
}
int main()
{
  int test , cs = 1;
  cin >> test;
  while(test--){
    int a, b, c , d;
    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    ull m , n , p , q;
    scanf("%llu.%llu.%llu.%llu",&m,&n,&p,&q);
    bool flag = 0;
    if(con(a) != m) flag = 1;
    if(con(b) != n) flag = 1;
    if(con(c) != p) flag = 1;
    if(con(d) != q) flag = 1;
    if(flag == 0) printf("Case %d: Yes\n", cs++);
    else printf("Case %d: No\n", cs++);
  }
 
}
