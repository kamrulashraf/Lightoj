#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (ll) 10000097
#define P 5000050
bool a[P];
vector <int> prime;
void seive(void){
 for(int i = 3 ; i*i<= N ; i+= 2)
    if(a[i>>1] == 0)
        for(int j = i*i ; j<= N ; j+= 2*i)
           a[j>>1] = 1;
 for(int i = 3 ; i<= N ; i+= 2)
    if(a[i>>1] == 0)
       prime.push_back(i);
 
 
}
 
int oddDivisor(ll num){
 ll ans = 1, temp, si = prime.size();
 while(num%2==0) num/= 2;
 temp = num;
 for(int i = 0 ; prime[i]*prime[i] <= temp && i< si ; i++){
    if(num%prime[i] == 0){
        int counter = 0;
        while(num%prime[i] == 0){
            counter++;
            num/=prime[i];
        }
        ans *= (counter+1);
    }
 }
 if(num > 1){
    ans *= 2;
 }
 return ans;
}
 
 
int main()
{
  seive();
 //  cout << prime[prime.size()-1]*prime[prime.size()-1] << endl;
  ll test, cse = 1, n;
  cin >> test;
  while(test--){
     scanf("%lld", &n);
     ll temp = oddDivisor(n);
     printf("Case %lld: %lld\n", cse++ , temp-1);
  }
}
