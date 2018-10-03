#include <bits/stdc++.h>
#define ll long long
using namespace std;
template < class T> inline T big(T b, T p, T M){
   if(!p) return 1;
   if(!(p&1)){
    T x = big(b,p/2,M);
    return (x%M * x%M)%M;
   }
   return (b%M * big(b,p-1,M)%M)%M;
}
int main()
{
   long long n , k , mod, arr[10005],sum, cse = 1;
   int test;
   cin >> test;
   while(test--){
     sum = 0;
     scanf("%lld %lld %lld", &n , &k , &mod);
     for(int i = 0 ; i< n ; i++){
         scanf("%lld", &arr[i]);
         sum += arr[i];
     }
     long long ans = big(n,k-1,mod);
     ans = (ans%mod * (k%mod) * (sum%mod))%mod;
     printf("Case %lld: %lld\n", cse++ , ans);
   }
 
 
}
