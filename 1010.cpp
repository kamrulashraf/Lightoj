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
int dp[1005][1005];
int lcs(string a , string b){
    for(int i = 1 ; i<= a.size() ; i++){
        for(int j = 1 ; j<= b.size() ;j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
        }
    }
 return dp[a.size()][b.size()];
}
int main()
{
   int test , cs = 1;
   int a ,b;
   long long ans;
   scanf("%d", &test);
   while(test--){
     scanf("%d %d", &a , &b);
     if(a > b) swap(a,b);
     if(a == 1){
        ans = a*b;
     }
     else if(a== 2 ){
        ans = b/4*4;
        if(b%4){
           if(b%4 == 1) ans += 2;
           else if(b%4 == 2 || b%4 == 3) ans += 4;
        }
     }
     else ans = ceil(a*b/2.0);
     printf("Case %d: %lld\n", cs++ ,ans);
   }
}
