// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define ff(x)        v[x].first
#define ss(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> inline T big(T b, T p, T M){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,M);
    return (x%M * x%M)%M;
   }
   return (b%M * big(b,p-1,M)%M)%M;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int main()
{
  ll test , n , cse = 1;
  cin >> test;
  while(test--){
    scanf("%lld", &n);
    ll counter = 0;
    while(n){
        if(n&1) counter++;
        n = (n>>1);
    }
    if(counter&1)
    printf("Case %lld: odd\n",cse++ , counter);
    else printf("Case %lld: even\n",cse++ , counter);
  }
 
}
