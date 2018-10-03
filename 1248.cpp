#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test  , cs = 1;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        double res = 0;
        for(double i = 1 ; i<= n ; i++){
            res += (double) n / i;
        }
        printf("Case %d: %.8lf\n",cs++, res);
    }
}
