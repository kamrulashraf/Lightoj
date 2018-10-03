#include <cstdio>
#include <iostream>
#include <math.h>
#define pi 2*acos (0.0)
using namespace std;
int main()
{
    double a  , d , r ;
    int test;
    int counter = 0;
    cin >> test;
    while(test--)
    {
        scanf("%lf" , &r);
 
        counter++;
        a =  4*r*r - pi*r*r;
        printf("Case %d: %.2lf\n",counter ,  a);
 
    }
 return 0;
}
 
