#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int test, num , sum,t,i, a;
    cin >> test;
    for(t = 0 ; t<test ; t++)
    {
        cin >> num;
        for(i = 0,sum = 0 ; i<num ; i++)
        {
            cin >> a ;
            if(a>0)
            sum += a;
        }
        printf("Case %d: %d\n", t+1 , sum);
    }
    return 0;
}
 
