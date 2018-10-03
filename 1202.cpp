#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long i , x , y , p , q , test;
    scanf("%lld", &test);
    for(i = 0 ; i< test ; i++)
    {
        scanf("%lld %lld %lld %lld", &x , &y , &p , &q);
        if(abs(x-p) == abs(y-q))
            printf("Case %lld: 1\n", i+1);
        else{
            if((x+y)%2 != (p+q)%2)
              printf("Case %lld: impossible\n", i+1);
            else  printf("Case %lld: 2\n", i+1);
 
        }
 
    }
 return 0;
}
 
