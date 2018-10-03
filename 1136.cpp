#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long i , j , t , a, b , result , r , test;
    scanf("%lld", &test);
    for(t = 1 ; t<= test ; t++)
    {
       scanf("%lld %lld", &a , &b);
       result = (b/3)*2;
       if(b%3 == 2) result++;
       a--;
       r = (a/3)*2;
       if(a%3==2) r++;
       printf("Case %lld: %lld\n" , t , result - r);
 
    }
 return 0;
}
