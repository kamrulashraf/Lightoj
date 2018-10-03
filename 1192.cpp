#include <bits/stdc++.h>
using namespace std;
#define NN 205
int main()
{
    int test , cs = 1;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d", &n);
        int a[NN] , b[NN];
        for(int i = 0 ; i< n ; i++)
            scanf("%d%d",&a[i], &b[i]);
        int res = 0;
        for(int i = 0 ; i<n ; i++){
            res ^= abs(b[i]-a[i]-1);
        }
 
 
        if(res > 0) printf("Case %d: Alice\n",cs++);
        else printf("Case %d: Bob\n",cs++);
    }
}
