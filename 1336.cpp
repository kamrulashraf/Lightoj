#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        long long a;
        scanf("%lld",&a);
        long long res = sqrt(a);
        res += sqrt(a/2);
        printf("Case %d: %lld\n",cs++ ,a-res);
    }
    return 0;
}
