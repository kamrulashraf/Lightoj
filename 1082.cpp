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
template < class T> inline T Set(T N, T pos){ return N = N | (1<< pos);}
template < class T> inline bool Check(T N , T pos){ return (bool) (N & (1<<pos));}
template < class T> inline T Reset(T N , T pos) { return N = N & ~(1 << pos); }
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
int tree[3*100005];
void make_tree(int node , int b , int e, int a[]){
 if(b==e){
    tree[node] = a[b];
    return;
 }
 int left = 2*node;
 int right = left+1;
 int mid = (b+e)/2;
 make_tree(left , b , mid , a);
 make_tree(right , mid+1 , e , a);
 tree[node] = min(tree[left],tree[right]);
}
 
int query(int node , int b , int e , int l , int u , int a[]){
  int mmin = 999999;
  if(u < b || l > e ){
    return 999999;
  }
  if( b >= l && e <= u){
    return tree[node];
  }
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  int p = query(left , b , mid , l , u , a);
  int q = query(right , mid+1 , e , l , u , a);
  mmin = min(p,q);
  return mmin;
 
}
int main()
{
  int n,q ,test, a[100005], cse = 1;
  cin >> test;
  while(test--){
    scanf("%d %d", &n , &q);
    rep(i,1,n+1){
        scanf("%d", &a[i]);
    }
    make_tree(1,1,n,a);
    printf("Case %d:\n", cse++);
    rep(i,0,q){
       int p,q;
       scanf("%d %d", &p , &q);
       int ans =  query(1,1,n,p,q,a);
       printf("%d\n", ans);
 
    }
  }
}
 
