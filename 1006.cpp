#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long int i , j , k;
    long long int test, arr[200000],n;
    scanf("%lld", &test);
    int caseno = 0;
    while(test--)
    {
        caseno++;
        for(i = 0 ; i<6 ; i++)
            scanf("%lld", &arr[i]);
 
 
 
        scanf("%lld", &n);
 
        for(i = 6 ; i<= n ; i++)
                arr[i] = (arr[i-6]%10000007 + arr[i-5]%10000007 + arr[i-4]%10000007 + arr[i-3]%10000007 + arr[i-2]%10000007 + arr[i-1]%10000007) %10000007;
            printf("Case %d: %lld\n", caseno , arr[n]%10000007);
    }
}
 
