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
template < class T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
bool a[50010];
std::vector<int > prime;
long long mod = 1000000007;
template < class T> T big(T b , T p , T mod){
    if(p == 0) return 1;
    if(!(p&1)){
        T x = big(b,p/2,mod);
        return (x*x)%mod;
    }
    else return (b*big(b,p-1,mod))%mod;
}
 
long long modInverse(ll n, ll mod){
  return big((ll) n,mod-2, mod);
}
 
inline void seive(long long num){
 
for(int i = 3 ; i*i <= num ; i+= 2)
  if(!a[i])
     for(int j = i*i ; j<= num ; j+= 2*i)
       a[j] = 1;
prime.push_back(2);
for(int i = 3 ; i<= num ; i+= 2)
    if(!a[i])
       prime.push_back(i);
}
 
long long nn = (1LL<<31)-1;
int n;
ll m;
 
long long factor(long long n){
     long long res = 1;
     for(int i = 0 ; i < prime.size() && prime[i]*prime[i] <= n ; i++){
          long long p = prime[i];
          long long counter = 0;
          if(n%p==0){
             while(n%p==0){
                counter++;
                n/=p;
             }
             counter *= m;
             res = (res*(big(p,counter+1,mod)-1))%mod;
             long long temp = modInverse(p-1,mod);
             res = (res*temp)%mod;
          }
     }
     if(n>1){
        res = (res*(big(n,m+1,mod)-1))%mod;
        long long tt = big(n,m+1,mod)-1;
        long long temp = modInverse(n-1,mod);
        res = (res*temp)%mod;
     }
     return res = (res+mod)%mod;
}
int main()
{
   int test , cs = 1;
   scanf("%d",&test);
   nn = sqrt(nn);
   seive(50000);
   while(test--){
       scanf("%d%lld",&n,&m);
       long long res = factor(n);
       printf("Case %d: %lld\n",cs++ ,res);
 
   }
 
}
