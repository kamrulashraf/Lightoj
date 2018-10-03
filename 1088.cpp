// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم //
//________________//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI            2.0*acos(0.0)   // acos(-1)
#define pi            pair <int,int>
#define rep(i,x,y)      for(int i = x ; i < y ; i++)
#define fst(x)        v[x].first
#define sd(x)         v[x].second
#define X(i)          x+fx[i]
#define Y(i)          y+fy[i]
#define INF  9999999
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
template < class T> inline T big(T b, T p, T N){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,N);
    return (x%N * x%N)%N;
   }
   return (b%N * big(b,p-1,N)%N)%N;
}
int fx[] = {0,1,0,-1,1,-1,1,-1};
int fy[] = {1,0,-1,0,1,-1,-1,1};
int a[100005];
int low(int b , int e , int key){
 
while(b<= e){
    int m = (b+e)/2;
    if(a[m] < key)
        b = m+1;
    else e = m-1;
}
 
return b;
}
 
int main()
{
  int temp ,test, cse=0;
  cin >> test;
  while(test--){
    int n ,q ;
    printf("Case %d:\n",++cse);
    cin >> n >> q;
    rep(i,0,n) scanf("%d", &a[i]);
    sort(a,a+n);
    a[n] = INF ;
    rep(i,0,q){
      int p , q;
      scanf("%d %d", &p , &q);
      p = low(0,n-1,p);
      temp = low(0,n-1,q);
      if(a[temp] != q ) temp--;
      printf("%d\n",temp-p+1);
 
    }
 
  }
}
