#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
#define ll long long
int main()
{
    ll i , a , b , test , caseno = 0, counter,num;
    map < ll , ll > hit;
    scanf("%lld", &test);
    while(test--)
    {
        caseno++;
        counter = 0;
        scanf("%lld", &num);
        for(i = 0 ; i < num ; i++)
        {
            scanf("%lld", &a);
            a++;
            if(hit[a] == 0)
            {
                counter += a;
            }
            hit[a]++;
            if(hit[a] == a) hit[a] = 0;
        }
        printf("Case %lld: %lld\n",caseno , counter);
        hit.clear();
    }
 return 0;
}

