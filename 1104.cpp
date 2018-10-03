#include <bits/stdc++.h>
using namespace std;
int main()
{
     int test , cs= 1;
     scanf("%d",&test);
     while(test--){
        double n;
        scanf("%lf",&n);
        double res = 1.00;
        int i;
        for( i = 0 ; i<= n ; i++){
             res *= (n-i)/n;
//            cout << res*100 << endl;
             if(res <= .5) break;
 
        }
        printf("Case %d: %d\n", cs++ ,i);
     }
}
