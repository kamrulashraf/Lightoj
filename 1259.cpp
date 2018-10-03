#include <bits/stdc++.h>
using namespace std;
bool a[10000007] = {1,1};
int prime[664580];
int sz;
inline void seive(long long num){
for(int i = 4 ; i<= num ; i+=2)
   a[i] = 1;
for(int i = 3 ; i*i <= num ; i+= 2)
  if(!a[i])
     for(int j = i*i ; j<= num ; j+= 2*i)
       a[j] = 1;
prime[sz++] = 2;
for(int i = 3 ; i<= num ; i+= 2)
    if(!a[i])  prime[sz++] = i;
}
 
int main()
{
    seive(10000003);
    int test , cs = 1;
    cin >> test;
    while(test--){
         int num,counter = 0;
         cin >> num;
         for(int i = 0 ; prime[i] <= num/2 ; i++){
            int temp = num - prime[i];
            if(prime[i] > temp) break;
            if(!a[temp]) counter++;
         }
        printf("Case %d: %d\n", cs++ , counter);
    }
 
}
