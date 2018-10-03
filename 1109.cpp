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
int a[1015];
vector <int> save;
 
void seive(){
    int root = sqrt(1000);
    for(int i = 3 ; i<= root ; i+=2)
      if(a[i]==0)
        for(int j = i*i ; j<= 1010 ; j+=2*i)
           a[j] = 1;
    save.push_back(2);
    for(int i = 3 ; i<= 1000 ; i+=2)
        if(a[i] == 0) save.push_back(i);
}
 
bool comp(pi a , pi b){
if(a.first == b.first){
        return a.second > b.second;
}
return a.first < b.first;
 
}
int nod(int n){
     int root = sqrt(n),ans = 1;
     for(int i = 0 ; save[i] <= root ; i++ ){
        if(n%save[i]==0){
            int counter = 1;
            while(n%save[i]==0){
                counter++;
                n/=save[i];
            }
           ans*= counter;
        }
     }
     if(n>1) ans *= 2;
     return ans;
}
int main()
{
  seive();
  vector < pi > v;
 
  for(int i = 1 ; i<= 1000 ; i++){
    int temp = nod(i);
    v.push_back(make_pair(temp,i));
  }
 
  sort(v.begin() , v.end() , comp);
 
  int test, n,cse=1;
  cin >> test;
  while(test--){
    scanf("%d", &n);
    printf("Case %d: %d\n", cse++ , v[n-1].second);
  }
}
